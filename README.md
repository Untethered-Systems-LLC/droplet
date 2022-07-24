# Droplet

A fast, contemporary and easy to use cross-platform graphical widget framework written in modern object-oriented C++. Part of the Fluid Project.

# Features

**Backends**
- [x] OpenGL
- [ ] Vulkan    - *Will be started after the framework reaches a stable and complete state on OpenGL, and when there are more volunteers.*

**Modules**

*A module will receive a checkmark, when it is at least 90% complete and is stable for use.*

- [ ] Animation
- [ ] Core
- [ ] Display
- [ ] Event
- [ ] Localisation
- [ ] Media
- [ ] Monitor
- [ ] Network
- [ ] Shader
- [ ] Shape
- [ ] Touch
- [ ] Widget
- [ ] Window

# Purpose

This framework is being developed as a part of the Fluid Project to serve as a means to develop its core applications and graphical interface. It is meant to be used as the standard way to write applications for the Fluid operating system on every device. Cross-platform compatibility is kept in mind to ensure that developers need not write platform-specific code in order to develop their software, without needing to resort to local PWA solutions, such as Electron.

# What you should not expect from this framework

This framework is not meant to replace softwares for game development and is not a substitute for a rendering API. Using this framework will assume you are running on a supported operating system. The progress of their support will be listed in the documentation later on.

# Metal and DirectX support

I am not going to focus on Metal and DirectX support for now. Contributors are welcome to provide support for their preferred backend. I personally see no benefit in supporting more rendering engines, because Vulkan is very performant and does everything any other API can do, while OpenGL is simpler in complexity and both are cross-platform as well (Vulkan works on macOS via MoltenVK). DirectX and Metal are proprietary software only supported on Windows and macOS respectively.

# Why should I use this framework when Qt already exists?

If Qt does the job well for you, go for it. I personally believe it's a great framework with a lot of functionality engrained,
but that comes with a lot of drawbacks, such as a steep learning curve, limitations in rendering backends and so on.

#  Documentation

You can read the framework's documentation [here](https://github.com/Untethered-Systems-LLC/droplet/wiki).