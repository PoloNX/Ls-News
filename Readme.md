<div align="center">
    <h1>Ls-News</h1>
    <p>An homebrew app for Nintendo Switch that allows you to read news from the Logic-Sunrise website.</p>
</div>

<p align="center">
    <a rel="LICENSE" href="https://github.com/PoloNX/AtmoPackUpdater/blob/master/LICENSE">
        <img src="https://img.shields.io/static/v1?label=license&message=GPLV3&labelColor=111111&color=0057da&style=for-the-badge&logo=data%3Aimage/png%3Bbase64%2CiVBORw0KGgoAAAANSUhEUgAAABQAAAATCAYAAACQjC21AAAACXBIWXMAAAsTAAALEwEAmpwYAAAAIGNIUk0AAHpFAACAgwAA/FcAAIDoAAB5FgAA8QEAADtfAAAcheDStWoAAAFGSURBVHjarJK9LgRhFIafWUuiEH/rJwrJClEq3IELUKgo3IrETWh0FC7BNVih0AoKBQoEydq11qMwm5yMsbPEm3yZd55zvnfO92VQKVhLak09UZeL%2BrsVZ9Qdv2tXnf1NYEndUushZFGthvemuq32FwWuq%2BeZid5DvZGpXambeYGr6qnd9dGldqaudQL3QuFWvVbbmaC6%2BprDr9WbwA4SdQW4BwaABb50CTykfjjwC%2BAx9SPAfOANYDxRCXpOnxNAM4ePA63Ul8NHR4E2QClsGgGG0jUR%2BFjglcAn8/pj4HTwUz/42FPJ68lOSDhCkR/O46XM0Qh3VcRH83jph%2BZefKUosBr8XA%2B%2BmufLAR4Dh6k/CrzWA691YOc/3Ejv6iNM3k59Xw%2B8D3gC9hN1ErjjfzSbqHVg8J8CG2XgBXgL4/9VCdD6HACaHdcHGCRMgQAAAABJRU5ErkJggg%3D%3D" alt=License>
    </a>
    <a rel="VERSION" href="https://github.com/PoloNX/AtmoPackUpdater">
        <img src="https://img.shields.io/static/v1?label=version&message=1.7.0&labelColor=111111&color=06f&style=for-the-badge" alt="Version">
    </a>
    <a rel="BUILD" href="https://github.com/PoloNX/AtmoPackUpdater/actions">
        <img src="https://img.shields.io/github/actions/workflow/status/PoloNX/AtmoPackUpdater/c-cpp.yml?branch=master &labelColor=111111&color=06f&style=for-the-badge" alt=Build>
    </a>
</p>




## Prerequisites

Before building and using the app, make sure you have the following dependencies installed on your system:

- switch-curl
- switch-glfw
- switch-mesa
- switch-glm

You can install these dependencies on your computer using the following command:

```
pacman -S switch-curl switch-glfw switch-mesa switch-glm
```

## Build Instructions

To build the app, follow these steps:

1. Clone the repo: ``git clone --recursive https://github.com/PoloNX/Ls-News``
2. Navigate to the repo directory: ``cd Ls-News``
3. Build the app: ``make``

## Usage

To use the app, copy the built ``Ls-News.nro`` file to your Nintendo Switch's `switch` directory and run it using your homebrew launcher.

## Acknowledgements

Special thanks to the following individuals and organizations for their contributions to this project:

- [XITRIX](https://github.com/XITRIX) and [natinusala](https://github.com/natinusala) for their [Borealis](https://github.com/XITRIX/borealis) homebrew framework, which served as the foundation for this project.
- The Logic-Sunrise website for their news content.
## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](https://github.com/PoloNX/Ls-News/blob/master/LICENSE) file for more details.
