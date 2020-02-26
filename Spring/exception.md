# Exception Handling

1. Clean up Resources in a finally block

2. Prefer specific Exceptions

``` java
public void doNot() throws Exception {
  ...
}


public void do() throws NumberFormatException {
  ...
}
```

3. Catch the most specific Exception first

``` java
public void do() {
    try {
        doSomething("A message");
    } catch (NumberFormatException e) {
        log.error(e);
    } catch (IllegalArgumentException e) {
        log.error(e)
    }
}
```

4. Don't Catch Throwable

Errors are thrown by the JVM to indicate serious problems that are not intended to be handled by an application. Typical examples for that are the OutOfMemoryError or the StackOverflowError.

5. Don’t Log and Throw

``` java
try {
    new Long("xyz");
} catch (NumberFormatException e) {
    log.error(e);
    throw e;
}
```

Reference
---
https://dzone.com/articles/9-best-practices-to-handle-exceptions-in-java
