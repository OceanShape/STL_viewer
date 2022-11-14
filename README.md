# STL_viewer
- `STL_viewer` is simple STL 3D model file(binary only) viewer

<p align="center">
<img src="https://user-images.githubusercontent.com/42532724/201099786-d507a09e-1af8-4138-a39b-41987f11e958.png"  width="30%"/> <img src="https://user-images.githubusercontent.com/42532724/201102436-55e8296e-ee1c-45e5-8506-7c12925fd411.png" width="30%"/>
</p>

## Environment
- OS: Windows 10
- Language: C++14
- API: OpenGL 1.0
- IDE: Visual Studio 2019

## Reference
- [jabhiji/stl-viewer](https://github.com/jabhiji/stl-viewer)
  - Standard rendering loop structure
  - Reading binary stl function

## How to Build
1. Install `vcpkg`
2. Install `opengl` libraries for `64bit` in `vcpkg`
    - `opengl`, `glew`, `glfw3`, `glm`, `glad`
3. Clone repository
4. Download and extract [STL Sample](https://drive.google.com/file/d/1I5Fjp9G3wr8GJKWY6ux9ZrOSxC_O9maw/view?usp=sharing) to `stl` directory same as `.sln` file)
5. Build and run on `Release(x64)`

## How to Use
- If you run `STL_viewer`, binary data is read and displayed on the screen.
  - You can change file name by editing `stllist.txt`.
- Press button for translate/rotate model.
  - `x-rotate`: `x`/`z`
  - `y-rotate`: `s`/`a`
  - `z-rotate`: `w`/`q`
  - `x-translate`: `right arrow`/`left arrow`
  - `y-translate`: `up arrow`/`down arrow`
  - `z-translate`: `e`/`d`
