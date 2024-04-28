<head>
	<link rel="stylesheet" type='text/css' href="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/devicon.min.css" />
</head>
<p align="center">
<h1 align="center">CUB3D</h1>
</p>
<p align="center">
    <em><code>The supreme raycaster</code></em>
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/apresas-97/cub3D.git?style=flat&color=0080ff" alt="license">
	<img src="https://img.shields.io/github/last-commit/apresas-97/cub3D.git?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/apresas-97/cub3D.git?style=flat&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/apresas-97/cub3D.git?style=flat&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
		<p align="center">Developed by <a href="https://github.com/apresas-97">😼​apresas-97</a> and <a href="https://github.com/cosmic3d">🌚​cosmic3d</a> with the software and tools below.</p>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/GNU%20Bash-4EAA25.svg?style=flat&logo=GNU-Bash&logoColor=white" alt="GNU%20Bash">
	<img src="https://img.shields.io/badge/programming_language-blue.svg?style=flat&logo=C&logoColor=white" alt="C">
	<img src="https://img.shields.io/badge/MinilibX-de65e0.svg?style=flat&logo=42&logoColor=white" alt="42 MLX">
	<img src="https://img.shields.io/badge/Makefile-fc9d21.svg?style=flat&logo=gnu&logoColor=white&logoSize=auto" alt="Makefile">
          
<!-- 	Añadir más herramientas como Makefile o MinilibX -->
 
  
</p>

<hr>


## 🔗 Quick Links

> - [📍 Overview](#-overview)
> - [📦 Features](#-features)
> - [🚀 Getting Started](#-getting-started)
>   - [⚙️ Installation](#️-installation)
>   - [🤖 Running cub3D](#-running-cub3D)
>   - [🎮 Controls](#-controls)
> - [📹 Game footage](#-game-footage)
> - [🛠 Project Roadmap](#-project-roadmap)
> - [🤝 Contributing](#-contributing)
> - [📄 License](#-license)
> - [👏 Acknowledgments](#-acknowledgments)

---

<h2>📍 Overview</h2>

<p><b>CUB3D</b> is a graphics project from the 42 campus. The goal was to create a 3D environment using a technique called <a href="https://en.wikipedia.org/wiki/Ray_casting">Raycasting</a> and the <strong>MinilibX library</strong> from the <strong>C programming language</strong>.</p>



---

## 📦 Features

- Raycasting technique used to draw walls
- Player and camera movement on X and Y axes
- Wall colisions
- Wall textures
- Animated sprites and interactive doors

---

## 🚀 Getting Started

***Requirements***

Ensure you have the following dependencies installed on your system:

- Requirements for MacOs
	- clang
	- make
	- This native version no longer uses X.org, XQuartez or X11 but uses **Mac OSX's Cocoa (AppKit)** and modern **OpenGL** features.

- Requirements for Linux
    - MinilibX only support TrueColor visual type (8,15,16,24 or 32 bits depth)
    - gcc
    - make
    - X11 include files (package xorg)
    - XShm extension must be present (package libxext-dev)
    - Utility functions from BSD systems - development files (package libbsd-dev)
    - e.g. sudo apt-get install gcc make xorg libxext-dev libbsd-dev (Debian/Ubuntu)

### ⚙️ Installation

1. Clone the cub3D repository:

```sh
git clone https://github.com/apresas-97/cub3D.git
```

2. Change to the project directory:

```sh
cd cub3D
```

3. Compile the project:

```sh
make
```

### 🤖 Running cub3D

Use the following command to run cub3D:

```sh
./cub3D <map>
```

Where *\<map\>* is a file with the .cub extension

---

## 🎮 Controls
- `WASD` for moving the player
- `⬅️➡️` or `🖱️ and left click` for moving the camera
- `E` for opening doors
- `ESC` for closing the game

---

## 📹 Game footage

<div align="center">
	<img style="width: 100%" src="https://github.com/apresas-97/cub3D/assets/68190267/eefaf14a-2c99-4ad3-b362-37de0425fd9d">
</div>
<div align="center">
	<img style="width: 100%" src="https://github.com/apresas-97/cub3D/assets/68190267/f153068b-7130-4a3b-a985-ce95e729a5ae">
</div>
<div align="center">
	<img style="width: 100%" src="https://github.com/apresas-97/cub3D/assets/68190267/ba18ff3e-68f2-4036-be0d-a554bd9484b2">
</div>


---

## 🛠 Project Roadmap

- [X] `► Raycasting technique used to draw walls`
- [X] `► Camera and player movement`
- [X] `► Textures are correctly drawn on the walls`
- [X] `► Better map parser`
- [X] `► Animated sprites and doors added`
- [X] `► Some custom maps added`
- [ ] `► Multiplayer`
---

## 🤝 Contributing

Contributions are welcome! Here are several ways you can contribute:

- **[Submit Pull Requests](https://github.com/apresas-97/cub3D.git/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.
- **[Join the Discussions](https://github.com/apresas-97/cub3D.git/discussions)**: Share your insights, provide feedback, or ask questions.
- **[Report Issues](https://github.com/apresas-97/cub3D.git/issues)**: Submit bugs found or log feature requests for Cub3d.

<details closed>
    <summary>Contributing Guidelines</summary>

1. **Fork the Repository**: Start by forking the project repository to your GitHub account.
2. **Clone Locally**: Clone the forked repository to your local machine using a Git client.
   ```sh
   git clone https://github.com/apresas-97/cub3D.git
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to GitHub**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.

Once your PR is reviewed and approved, it will be merged into the main branch.

</details>

---

## 📄 License

This project is protected under the [MIT]([https://choosealicense.com/licenses](https://opensource.org/license/mit/)) License. For more details, refer to the [LICENSE](LICENSE) file.

---

## 👏 Acknowledgments

- List any resources, contributors, inspiration, etc. here. ALBERT SI VES ESTO PON AQUÍ LO QUE QUIERAS QUE YO NO SÉ QUÉ PONER

[**Return**](#-quick-links)

---
