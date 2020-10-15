# Integrating Prettier + ESLint + Airbnb Style Guide in VSCode

1. Download the **ESLint** and **Prettier** extensions for VSCode
2. Install the ESLint and Prettier libraries

```bash
npm install -D eslint prettier
```

3. If you’re using npm 5+, install the Airbnb config.

```bash
npx install-peerdeps --dev eslint-config-airbnb
```

4. Install eslint-config-prettier, eslint-plugin-prettier

```bash
npm install -D eslint-config-prettier eslint-plugin-prettier
```

5. .eslintrc.json

```json
{
  "extends": ["airbnb", "prettier"],
  "plugins": ["prettier"],
  "rules": {
    "prettier/prettier": ["error"]
  }
}
```

6. .prettierrc

```json
{
  "printWidth": 100,
  "singleQuote": true,
  "trailingComma": true
}
```

7. vscode

```json
 "editor.formatOnSave": true
```

---

### Reference

https://blog.echobind.com/integrating-prettier-eslint-airbnb-style-guide-in-vscode-47f07b5d7d6a
https://gist.github.com/ChoWonmin/aa4f5757a28bcbfd9e38c7d1b0d1a514
