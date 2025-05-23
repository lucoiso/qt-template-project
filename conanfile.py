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
        self.requires("qt/6.7.3")

        # https://conan.io/center/recipes/boost
        self.requires("boost/1.87.0")

        # https://conan.io/center/recipes/benchmark
        self.requires("benchmark/1.9.1")

        # https://conan.io/center/recipes/catch2
        self.requires("catch2/3.8.0")

    def configure(self):
        self.options["qt/*"].shared = True
        self.options["qt/*"].qtdeclarative = True
        self.options["qt/*"].qtshadertools = True
        self.options["boost/*"].shared = True
        self.options["boost/*"].without_cobalt = True
        self.options["benchmark/*"].shared = True
        self.options["catch2/*"].shared = True
        self.options["catch2/*"].enable_exceptions = True

    def build_requirements(self):
        self.tool_requires("cmake/[>=3.29]")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self, generator="Ninja")
        tc.variables["QT_LOGGING_TO_CONSOLE"] = "1"
        tc.variables["QT_FORCE_STDERR_LOGGING"] = "1"
        tc.variables["QT_ASSUME_STDERR_HAS_CONSOLE"] = "1"
        tc.variables["QML_IMPORT_TRACE"] = "0"
        tc.generate()
