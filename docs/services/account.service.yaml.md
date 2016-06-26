---
title: "Account"
---

Provides methods for managing users. Used by the frontend.

#### CreateToken
Generate a personal access token that can be passed in GET parameters instead user/psk pair

Arguments:
- `description`: displayed when listing the tokens

Result `string`: 
#### ListTokens
List tokens


Result `array`: 
#### CreateUser
Creates a new user. Can only be called by the frontend.

Arguments:
- `password`: Password for the user.
- `email`: User's email address.
- `name`: Display name for the user.
- `id`: ID for the new user.

Request:
```json
{
  "v": 2,
  "src": "device_123",
  "id": 123,
  "method": "/v1/Account.CreateUser",
  "args": {
    "email": "VALUE PLACEHOLDER",
    "id": "VALUE PLACEHOLDER",
    "name": "VALUE PLACEHOLDER",
    "password": "VALUE PLACEHOLDER"
  }
}

```

Response:
```json
{
  "v": 2,
  "src": "//api.cesanta.com",
  "dst": "device_123",
  "id": 123
}

```

#### GetInfo
Retrieves info about an existing user. If id is present, info is fetched by id. Otherwise, if name is present, info is fetched by name. Otherwise, it's an error.

Arguments:
- `id`: ID of the user.
- `name`: Name of the user.

Result `object`: 
Request:
```json
{
  "v": 2,
  "src": "device_123",
  "id": 123,
  "method": "/v1/Account.GetInfo",
  "args": {
    "id": "VALUE PLACEHOLDER",
    "name": "VALUE PLACEHOLDER"
  }
}

```

Response:
```json
{
  "v": 2,
  "src": "//api.cesanta.com",
  "dst": "device_123",
  "id": 123,
  "result": "VALUE PLACEHOLDER"
}

```

#### RevokeToken
Delete the token

Arguments:
- `token`: 

#### UserExists
Returns whether the user exists

Arguments:
- `id`: ID of the user.
- `name`: Name of the user.

Result `object`: 
#### ValidateToken
validates a token and returns the user ID associated with it

Arguments:
- `token`: 

Result `object`: 
