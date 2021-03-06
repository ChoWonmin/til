# React Native

- Create native apps for Android and iOS using React
- Written in JavaScript—rendered with native code
- Native Development For Everyone
- - It provides a core set of platform agnostic native components like View, Text, and Image that map directly to the platform’s native UI building blocks
- Seamless Cross-Platform
- React components wrap existing native code and interact with native APIs via React’s declarative UI paradigm and JavaScript.
- Facebook Supported, Community Driven

---

## Getting Started

### 1. new to mobile development

Expo CLI

> set of tools built around React Native and, while it has many features

#### install Expo

- Node 10 LTS or greater installed

```bash
npm install -g expo-cli

expo init AwesomeProject

cd AwesomeProject
npm start # you can also use: expo start
```

#### install Expo on my phon

- same wireless network

---

### 2. already familiar with mobile development

#### 2-1. IOS

```md
Prerequisite

- Node # 8.3 or newer
- Watchman : tool by Facebook for watching changes in the filesystem. It is highly recommended you install it for better performance.
- React Native command line interface
- Xcode # 9.4 or newer
```

#### install node, watchman

```bash
brew install node # 8.3 or newer
brew install watchman
```

#### Command Line Tools

1. open XCode
2. Preferences
3. Locations panel
4. Install the tools by selecting the most recent version in the Command Line Tools dropdown

#### Installing an iOS Simulator in Xcode

1. Xcode > Preferences
2. Components
3. Select a simulator with the corresponding version of iOS you wish to use

#### CocoaPods

built with Ruby and it will be installable with the default Ruby available on macOS

```
sudo gem install cocoapods
```

---

#### 3-1. Android

```md
Prerequisite

- Node # 8.3 or newer
- Watchman : tool by Facebook for watching changes in the filesystem. It is highly recommended you install it for better performance.
- React Native command line interface
- JDK # JDK 8 or newer
- Android Studio
```

#### Java Development Kit

```
brew tap AdoptOpenJDK/openjdk
brew cask install adoptopenjdk8
```

#### Android development environment

1. [Install Android Studio](https://developer.android.com/studio/index.html)

- Android SDK
- Android SDK Platform
- Performance (Intel ® HAXM) (See here for AMD)
- Android Virtual Device

2. Install the Android SDK

Appearance & Behavior → System Settings → Android SDK.

3. Configure the ANDROID_HOME environment variable

```bash
# $HOME/.bash_profile or $HOME/.bashrc

export ANDROID_HOME=$HOME/Library/Android/sdk
export PATH=$PATH:$ANDROID_HOME/emulator
export PATH=$PATH:$ANDROID_HOME/tools
export PATH=$PATH:$ANDROID_HOME/tools/bin
export PATH=$PATH:$ANDROID_HOME/platform-tools
```

---

#### Creating and Run new application

```bash
npx react-native init AwesomeProject

# specific version
npx react-native init AwesomeProject --version X.XX.X

# typescript template
npx react-native init AwesomeTSProject --template react-native-template-typescript

# run
npx react-native run-ios
npx react-native run-android
```

---

## Reference

- https://reactnative.dev/docs/getting-started
- https://expo.io/features
- https://snack.expo.io/

```

```
