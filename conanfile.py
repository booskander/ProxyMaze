from conan import ConanFile

class ProxyMaze(ConanFile):
    generators = ("CMakeToolchain", "CMakeDeps")
    settings = ("os", "build_type", "arch", "compiler")

    def requirements(self):
        self.requires('cpp-httplib/0.15.3')
        self.requires('jsoncpp/1.9.5')

    def build_requirements(self):
        self.tool_requires("cmake/[>=3.25]")

    def layout(self):
        self.folders.generators = ""