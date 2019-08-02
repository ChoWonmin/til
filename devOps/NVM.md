# NVM

> ## Node Version Manager

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


