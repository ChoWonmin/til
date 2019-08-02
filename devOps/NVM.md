# NVM

> ## [Node Version Manager](https://github.com/nvm-sh/nvm)

---

## Usage

``` bash
# install node (v8.10.0)
nvm install v8.10.0

# use or chage node version
nvm use v8.10.0

# show node list and check current version
nvm list
```

---

## install

### 1. mac os

``` bash
brew install nvm

# write an alias to terminal profile as
echo "source $(brew — prefix nvm)/nvm.sh" >> .bash_profile

# iTerm, zsh and on-my-zsh not bash
echo "source $(brew — prefix nvm)/nvm.sh" >> .zhsrc

# activate configuration
~/.bash_profile

# to zsh
. ~/.zshrc
```

#### error message

```
nvm is not compatible with the npm config "prefix" option: currently set to "/Users/fabian/.nvm/versions/node/v8.10.0" Run `nvm use - delete-prefix v6.5.0` to unset it.
```

- remove node files controlled by nvm
``` bash
#check all module installed.
$ npm ls -g — depth=0

#delete node_modules folders
$ sudo rm -rf /usr/local/lib/node_modules

#delete node
$ sudo rm /usr/local/bin/node

#delete global node module alias
$ cd /usr/local/bin && ls -l | grep “../lib/node_modules/” | awk ‘{print $9}’| xargs rm
```

- restart terminal and install nvm by curl
``` bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.34.0/install.sh | bash
```
