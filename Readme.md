English : [readme](https://github.com/PoloNX/Ls-News/blob/master/Readme_english.md)


<div align="center">
    <h1>Ls-News</h1>
    <p>Un homebrew pour la nintnedo Switch qui vous permet de lire les dernières news du site Logic-Sunrise.</p>
</div>

<p align="center">
    <a rel="LICENSE" href="https://github.com/PoloNX/AtmoPackUpdater/blob/master/LICENSE">
        <img src="https://img.shields.io/static/v1?label=license&message=GPLV3&labelColor=111111&color=0057da&style=for-the-badge&logo=data%3Aimage/png%3Bbase64%2CiVBORw0KGgoAAAANSUhEUgAAABQAAAATCAYAAACQjC21AAAACXBIWXMAAAsTAAALEwEAmpwYAAAAIGNIUk0AAHpFAACAgwAA/FcAAIDoAAB5FgAA8QEAADtfAAAcheDStWoAAAFGSURBVHjarJK9LgRhFIafWUuiEH/rJwrJClEq3IELUKgo3IrETWh0FC7BNVih0AoKBQoEydq11qMwm5yMsbPEm3yZd55zvnfO92VQKVhLak09UZeL%2BrsVZ9Qdv2tXnf1NYEndUushZFGthvemuq32FwWuq%2BeZid5DvZGpXambeYGr6qnd9dGldqaudQL3QuFWvVbbmaC6%2BprDr9WbwA4SdQW4BwaABb50CTykfjjwC%2BAx9SPAfOANYDxRCXpOnxNAM4ePA63Ul8NHR4E2QClsGgGG0jUR%2BFjglcAn8/pj4HTwUz/42FPJ68lOSDhCkR/O46XM0Qh3VcRH83jph%2BZefKUosBr8XA%2B%2BmufLAR4Dh6k/CrzWA691YOc/3Ejv6iNM3k59Xw%2B8D3gC9hN1ErjjfzSbqHVg8J8CG2XgBXgL4/9VCdD6HACaHdcHGCRMgQAAAABJRU5ErkJggg%3D%3D" alt=License>
    </a>
    <a rel="VERSION" href="https://github.com/PoloNX/AtmoPackUpdater">
        <img src="https://img.shields.io/static/v1?label=version&message=1.0.0&labelColor=111111&color=06f&style=for-the-badge" alt="Version">
    </a>
    <a rel="BUILD" href="https://github.com/PoloNX/AtmoPackUpdater/actions">
        <img src="https://img.shields.io/github/actions/workflow/status/PoloNX/Ls-News/c-cpp.yml?branch=master &labelColor=111111&color=06f&style=for-the-badge" alt=Build>
    </a>
</p>




## Build l'homebrew

Avant de build l'homebrew, il faut installer les dépendances suivantes sur votre système dôté d'un [environnement de développement pour switch](https://ls-atelier-tutos.fr/environnement%20de%20developpement%20switch.php):

- switch-curl
- switch-glfw
- switch-mesa
- switch-glm

Vous pouvez installer ces dépendances en utilisant la commande suivante :

```
pacman -S switch-curl switch-glfw switch-mesa switch-glm
```

Pour build l'app, suivez ces étapes:

1. Clonee le repo: ``git clone --recursive https://github.com/PoloNX/Ls-News``
2. Navigez vers le répertoire du repo: ``cd Ls-News``
3. Build l'homebrew: ``make``

## Utilisation

Pour utiliser l'homebrew, copiez ``Ls-News.nro`` dans le répetoire ``switch`` de votre carte micro-sd. Vous pouvez ensuite le lancer via l'homebrew launcher.

## Remerciements

Merci au différentes personnes et organisations pour leurs contributions au projet:

- [XITRIX](https://github.com/XITRIX) et [natinusala](https://github.com/natinusala) pour [Borealis](https://github.com/XITRIX/borealis), qui a servis dans le développement du projet.
- Le site logic-sunrise pour leurs news.
## License

Ce projet est sous licence GNU General Public License v3.0. Veuillez consulter le fichier [LICENSE](https://github.com/PoloNX/Ls-News/blob/master/LICENSE) pour plus de détails.
