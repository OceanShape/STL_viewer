# STL_viewer
- STL_viewer is simple STL 3D model file(binary only) viewer

## Reference
- [jabhiji/stl-viewer](https://github.com/jabhiji/stl-viewer)
  - Standard rendering loop structure
  - Reading binary stl function

## 환경 구성
1. 아래의 링크를 참고하여, vcpkg opengl 환경 구축
    - [https://musket-ade.tistory.com/51](https://musket-ade.tistory.com/51)
    - vcpkg로 설치하는 모든 라이브러리는 64bit 버전 설치를 위해, 뒤에 `:x64-windows`를 추가한다
      - vcpkg install opengl:x64-windows
      - vcpkg install glew:x64-windows
      - vcpkg install glfw3:x64-windows
2. opengl/glew/glfw3 설치 이후, 아래의 커맨드를 입력하여 glm/glad 라이브러리를 추가한다
    - vcpkg install glm:x64-windows
    - vcpkg install glad:x64-windows
    - vcpkg integrate install 커맨드 한번 더 실행
3. git clone을 사용하여, [https://github.com/OceanShape/STL_viewer.git](https://github.com/OceanShape/STL_viewer.git) 리포지토리 다운로드
4. 아래 링크의 파일(stl.7z) 다운로드
    - [https://drive.google.com/file/d/1I5Fjp9G3wr8GJKWY6ux9ZrOSxC_O9maw/view?usp=sharing](https://drive.google.com/file/d/1I5Fjp9G3wr8GJKWY6ux9ZrOSxC_O9maw/view?usp=sharing)
5. .sln파일과 동일한 디렉토리에 stl.7z의 압축을 푼다(폴더 이름: stl)
6. sln파일을 통해 Visual Studio 실행
7. Release(x64)환경에서 빌드 및 실행(Ctrl + f5)
