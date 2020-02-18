# JWT

- Base64Url

## Structure

### Header
``` json
{
  "alg": "HS256", //HMAC SHA256, RSA
  "typ": "JWT"
}
```

### Payload
Payload contains claims.
Claims are statements about an entity(the user) and additional data.

- Registered claims
- Public claims
- Private claims

``` json
{
  "sub": '1234567890',
  "name": "John Doe",
  "admin": true
}
```



---
https://jwt.io/introduction/
