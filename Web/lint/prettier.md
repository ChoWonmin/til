# Prettier

### 1. install

```
npm i prettier
```

### 2. run prettier

- 설정 없이 사용 가능

```bash
npx prettier src/**/*
npx prettier src/**/* --write #auto fix
```

### 3. intergrate elint

install

```
npm i eslint-config-prettier eslint-plugin-prettier
```

.eslintrc.js

```js
module.exports = {
  extends: ["eslint:recommended", "plugin:prettier/recommended"],
};
```

### 4-1. git hook

```bash
# lint-staged : 변경된(스테이징된) 파일만 린트를 수행
npm i husky lint-staged
```

```json
{
  "husky": {
    "hooks": {
      "pre-commit": "lint-staged"
    }
  },
  "lint-staged": {
    "*.js": "npm run lint"
  }
}
```

### 4-2. vscode editer

1. install ESlint vscode extendsion

2. setting.json

    현재 워크스페이스에 설정하기
    
    ctrl + shift + p  > Open workspace Settings (JSON)
    
    .vscode > setting.json 생성

```json
{
  "eslint.enable": true,
  "editor.codeActionsOnSave": {
    "source.fixAll.eslint": true
  }
}
```
