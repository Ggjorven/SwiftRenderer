import shutil as sh
import os

def main() -> None:
    print("-----------------------------")
    print("Installing ImGui into Swift.")
    print("-----------------------------\n")

    print(f"Current working directory: {os.getcwd()}\n")

    sh.copy2("src/ImGui/Files/Application.cpp", "../../Core/src/Swift/Core/Application.cpp")
    sh.copy2("src/ImGui/Files/Application.hpp", "../../Core/src/Swift/Core/Application.hpp")

    sh.copy2("src/ImGui/Files/BaseImGuiLayer.cpp", "../../Core/src/Swift/Utils/BaseImGuiLayer.cpp")
    sh.copy2("src/ImGui/Files/BaseImGuiLayer.hpp", "../../Core/src/Swift/Utils/BaseImGuiLayer.hpp")

    sh.copy2("src/ImGui/Files/ImGuiBuild.cpp", "../../Core/src/Swift/Utils/ImGuiBuild.cpp")

    sh.copy2("src/ImGui/Files/Layer.hpp", "../../Core/src/Swift/Core/Layer.hpp")

    sh.copy2("src/ImGui/Files/VulkanImGuiLayer.cpp", "../../Core/src/Swift/Vulkan/VulkanImGuiLayer.cpp")
    sh.copy2("src/ImGui/Files/VulkanImGuiLayer.hpp", "../../Core/src/Swift/Vulkan/VulkanImGuiLayer.hpp")

    print("-----------------------------")
    print("Finished installing ImGui...")
    print("-----------------------------")

    print("\nDon't forget to reload/regenerate the project.\n")

if __name__ == '__main__':
    main()