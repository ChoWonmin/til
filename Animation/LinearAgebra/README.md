# Linear Algebra

> 세상은 Vector, Scala, Matrix로 표현 가능 

## Vectors
### properties
- number array(n개의 실수를 나타내는 표현식) => n개의 자유도를 가진다.
- 이를 기하학에 적용 ex) 3차원 벡터
- 선으로 표현 가능

### operation
##### 1. Addition

##### 2. Scalar multiplication (scaling)

##### 3. Linear Combination
> - *a1***v1** + *a2***v2** + *a3***v3** + *a4***v4** + ... 식으로 표현가능한 형태 
> - 직선의 방정식으로 표현 가능

##### 4. vector space
> - set of vector that can be built by linear combinations of the (basis) vector
> - if **v1**, **v2** is zero vector, vector space is zero vector
> - if **v1**, **v2** is zero vector, vector space is zero vector

##### 5. Linearly dependent : 선형적으로 종속적이다
> - vector is a linear combination of the other. In this case the dimensionality of the space spanned by the vectors is smaller than the original vector
#####Example
> - **v** = *a1***v1** + *a2***v2** => 자유도는 *a1*, *a2*로 2개라서 평면 표현이 가능하다
> - But 3*x* + 4*y* = 5, 6*x* + 4*8* = 10 같이 Linearly dependent 경우는 제외
> - 즉, ad-bc가 0인 경우, 역행렬이 없는 경우

### Combinations
##### 1. Linear Combinations
> *a1***v1** + *a2***v2** + *a3***v3** + *a4***v4** + ...
##### 2. Affine Combinations
> *a1* + *a2* + *a3* + *a4* + *a5* + ... = 1
##### 3. Convex Combinations
> 0 <= *a1* ... *a***n** <= 1

### Dot product
```
|a|   |d|           |d|
|b| . |e| = [a b c] |e| = ad + be + cf
|c|   |f|           |f|
```
##### 1. vector length (Magnitude)
```
     |a|
a  = |b|   ||a|| = sqrt{a^2 + b^2 + c^2} = 
     |c| , 
```
##### 2. Normalization : 방향만 알고 싶은 경우
> unit vector : a vector with length of 1
```
```

