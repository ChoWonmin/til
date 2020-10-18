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
module.ecports = {
  extends: ["eslint:recommended", "plguin:prettier/recommended"],
};
```
