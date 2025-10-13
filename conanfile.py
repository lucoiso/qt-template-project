# Copyright Notices: [...]

from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMakeToolchain


class QtTemplateProjectRecipe(ConanFile):
    name = "qt-template-project"
    version = "0.0.1"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"

    def requirements(self):
        # https://conan.io/center/recipes/qt
        self.requires("qt/6.8.3")

    def configure(self):
        self.options["qt/*"].shared = True
        self.options["qt/*"].qtdeclarative = True
        self.options["qt/*"].qtshadertools = True
        self.options["qt/*"].with_vulkan = True
        self.options["qt/*"].opengl = "no"

    def build_requirements(self):
        self.tool_requires("cmake/[>=3.29]")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self, generator="Ninja")
        tc.generate()
