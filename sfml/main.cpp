#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

#include "ShapeFactory.h"

using json = nlohmann::json;

int main() {
    // --- Load config_openGl.json ---
    std::ifstream file(std::string(CONFIG_DIR) + "/config_sfml.json");
    if (!file.is_open()) {
        std::cerr << "Error opening config_sfml.json\n";
        return -1;
    }

    json config;
    file >> config;

    // --- Extract window & rendering settings ---
    int width = config["window"]["width"];
    int height = config["window"]["height"];
    std::string title = config["window"]["title"];
    int fps = config["rendering"]["fps"];
    auto clear_color = config["rendering"]["clear_color"];
    std::string style = config["imgui"]["style"];

    std::ifstream shapesFile(std::string(CONFIG_DIR) + "/shapes_config.json");
    if (!shapesFile.is_open()) {
        std::cerr << "Error opening shapes_config.json\n";
        return -1;
    }

    shapesFile >> config;

    auto shapes = ShapeFactory::loadShapes(config);

    // --- Create SFML window ---
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    window.setFramerateLimit(fps);

    // Color conversion for SFML 2.6.x
    sf::Color bgColor(
        static_cast<sf::Uint8>(clear_color[0].get<float>() * 255),
        static_cast<sf::Uint8>(clear_color[1].get<float>() * 255),
        static_cast<sf::Uint8>(clear_color[2].get<float>() * 255)
    );

    // --- Initialize ImGui-SFML ---
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // --- Set ImGui style ---
    if (style == "Dark") ImGui::StyleColorsDark();
    else if (style == "Light") ImGui::StyleColorsLight();
    else ImGui::StyleColorsClassic();

    // Initialization for ImGui-SFML 2.6.x
    if (!ImGui::SFML::Init(window)) {
        std::cerr << "Failed to initialize ImGui-SFML\n";
        return -1;
    }

    // --- Main loop ---
    sf::Clock deltaClock;
    while (window.isOpen()) {
        // Event handling for SFML 2.6.x
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // --- Start ImGui frame ---
        ImGui::SFML::Update(window, deltaClock.restart());

        // --- Show ImGui window ---
        ImGui::Begin("Objects");
        size_t currentIndex = 0;

        if (ImGui::BeginCombo("Select Object", shapes[currentIndex] -> name.c_str())) {
            for (size_t i=0; i < shapes.size() ; i++) {
                bool isSelected = (currentIndex == i);
                if (ImGui::Selectable(shapes[i] -> name.c_str(), isSelected)) {
                    currentIndex = i;
                }
                if (isSelected) {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }
        shapes[currentIndex] -> showImgui();

        ImGui::End();

        // --- Update Velocity ---
        for (auto& s: shapes) {
            s->update(window);
        }

        // --- Render SFML + ImGui ---
        window.clear(bgColor);
        for (auto& s : shapes) {
            s->draw(window);
        }
        ImGui::SFML::Render(window);
        window.display();
    }

    // --- Cleanup ---
    ImGui::SFML::Shutdown();
    ImGui::DestroyContext();

    return 0;
}