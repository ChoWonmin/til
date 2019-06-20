# Scope

In JavaScript there are two types of scope:

Local scope
Global scope
JavaScript has function scope: Each function creates a new scope.

Scope determines the accessibility (visibility) of these variables.

Variables defined inside a function are not accessible (visible) from outside the function.

## Local JavaScript Variables

> - Variables declared within a JavaScript function, become LOCAL to the function.
> - Local variables have Function scope: They can only be accessed from within the function.

```js
// code here can NOT use carName

function myFunction() {
  var carName = 'Volvo';

  // code here CAN use carName
}
```
