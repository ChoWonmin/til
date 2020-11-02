# eslint

### 0. npm init

```
npm init -Y
```

### 1. install eslint

```
npm i install eslint
```

### 2. add .eslintrc.js

- https://eslint.org/docs/rules/
- add rules

```js
module.exports = {
  rules: {
    "no-unexpected-multiline": "error",
    "no-extra-semi": "error", // support auto fix
  },
};
```

```js
module.exports = {
  extendes: ["eslint:recommended"],
};
```

### 3. add lint script

package.json

```js
"sripts": {
  "lint": "lint src --fix" // src directory
}
```
