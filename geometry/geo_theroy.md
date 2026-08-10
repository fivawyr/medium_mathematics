### Linear Algebra 
> I mostly skip vector and point theory, since everybody got taught this in highschool (I hope so). One sidenote, Mathematics and physiscsits, often adopt a more gneralized view on vectors, where there can encompass as an arbitrary or even infinite number of elements, which is far above the CS scope. We make it simpler 
- A Vector represends a direction and a **magnitude** within a 3 dimensional space. 
- A **homogeneous coordinate system** uses a third coordinate to represend transformation and rotation of points. There are used, because with the third coordinate, we are able to calc the scalability, transformation and rotation just with simple matrix operation &rarr; inhomogeneous coordinates systems requiere an additional matrix addition $P_H(x,y,z,w)$
#### Quick rewind on transformation and rotation 
1. Transformation is a fundamental operation that involvves moving points to different location in space (without changing its magnitude). Since we cant change the direction or magnitude of the vector, the vector will be the same, just the O (starting position) will be changed 
2. Rotation means we change the direction of a vector but keeping its magnitude and O the same

$$
- Point transformation: P \rarr Translate \rarr P_T
$$

$$
- Vector transformation: V \rarr Rotate \rarr V_T
$$

3. When the magnitude of a vector is exactly 1, we call it a **normalized vector**. Normalization is a common requirement in CG for simplifying calculations and ensure consistencsy across differnt operations. Yet, there are scenarios where maintaining the original legnth of a vector is beneficial, such as when the vector represents a specific distance between two points, prividing both direction and the measure of separation between them 
### Normals
- A surface normal at a point is essentially a vector that is perpendicular (senkrecht) to the **tangent plane** at that point. This means it points directly away from the surface, indicating its orientation in three-dimensional space
- Normals are indispensable for shading for termine the brightness and color of surfaces in a scene based on the light sources present. By having information about normals, algorithms can accurately simulate the feffects of light on different parts of an object, contributing to trhe realism and depth of the rendered scene.
- (!) even though normals and vectors have the same structure, the transformation process for normals are different than for vectors. 
### Coordinate systems
- we use the right-/left hand coordinate system, where the thumb represents the x axis, your index finger the y/z axis and the middlefinger your z/y axis
> in Physics/Mechanics we are using the z axis to go up and the y axis to go deep. This is the oppusite as in Mathematics/Computer Science! 
### Operations 
- Vector Length: 

$$
\|V\| = \sqrt{(V.x * V.x) + (V.y * V.y) + (V.z * V.z)}
$$

- normalize a vector &rarr; calculate the vectors length and then divide each coordinates of the vector by its legntt: $\hat{V} = \frac{V}{\|V\|}$
- to avoid a division by 0, only normalize a vector if the **vector length is greater than zero** (!)
- Dot product (scalar product) &rarr; the dot product of two vectors can be seen as the projection of A over B. If the two vectors A and B have unit length, then the result of the dot product is the cosine of the angle subtended by the two vectos ($\|A\|cos(\theta)$)

$$
A \cdot B = (A.x * B.x) + (A.y * B.y) + (A.z * B.z)
$$

- If B is a unit vector, the operation $A \cdot B$ yields to $\|A\|cos(\theta)$, signifying the magnitude of A's projection in B's direciton with a negative sign if the direction is reversed. This is termed the scalar projection of A onto B
- For cases where neither A or B is a unit vector, the expression can adjusted to $A \cdot \frac{B}{\|B\|}$, recognizing $B/\|B\|$ as B represented as a unit vector
-When When boht vectors are normalized, the arc cosine$(cos^-1$) of their dot product reveals the angle $\theta$ between them: $\theta$ = $cos^-1 (\frac{A\cdotB}{\|A\|\|B\|})$ or $\theta cos^-1(\hat{A}\codt\hat{B}$, where $cos^-1$ denotes the inverse cosine function, commonly presented as acos() in programming languages 
#### Cross product 
- unlike the dot product, the cross product results in a vector. The uniqueness of this operation lies in the resultant vector being perpendicular to the plane defined by the two original vectors $C = A \cross B$. 

$$
C_X = A_Y \cross B_Z - A_Z \cross B_Y 
C_Y = A_Z \cross B_X - A_X \cross B_Z
C_Z = A_X \cross B_Y - A_Y \cross B_X
$$

- the corss product $A \cross B$ results in the vector C, that is **orthogonal to both A and B**. These two vectors define a plane and C s tands perpendicular to this plane. The vectors A and B need not be perpendicular themselves, but when they are, and assuming they are of unit legnth, they form a Cartesian coordinate system with C. This concept is instrumental in construction coordinate systems.  
- the cross product is described as anticommunative, meaning that exchanging the positions of the two vectors inverses the result (turns into -C). 
- In math, the output of a cross product is termed as **pseudo vector**. The sequence in which vectors participate in the cross product is critical, especially when computing surface normals from the tangent and bitengent at a point. The sequence determines wether the resulting normal points inwards or outwards relative to the surface
### Matrcies
- a matrix combines all the vector operation that we just learned (transformation, rotation, scalability) tinto a unified entity (einheitliche Größe). 
- In computer science context, matrices are two-dimensional arrays of numbers. This array is described by the notation $m x n$ where m and n denote the arrays dimension. Here, m and n correspond to the number of rows and columns (rc) 
#### Matrix multiplication
- $[M \cross P] * [P \cross N] = [M \cross N]$
$$
M1 = \begin{bmatrix} c_00 & c_01 & c_02 & c_03 \cr c_10 & c_11 & c_12 & c_13 \cr c_20 & c_21 & c_22 & c_23 \cr c_30 & c_31 & c_32 & c_32\end{bmatrix} M2 = \begin{bmatrix} c_00 & c_01 & c_02 & c_03 \cr c_10 & c_11 & c_12 & c_13 \cr c_20 & c_21 & c_22 & c_23 \cr c_30 & c_31 & c_32 & c_33\end{bmatrix}
$$
$$
M3_12 = \begin{bmatrix} M1_10 * M2_02 + \cr M1_11 * M2_12 + \cr M1_12 * M2_22 + \cr M1_13 * M2_32 \end{bmatrix}
$$
Identity matrix: 
$$
\begin{bmatrix} 1 & 0 & 0 \cr 0 & 1 & 0 \cr 0 & 0 & 1 \end{bmatrix}
$$
#### Rotation of a matrix
- lets say on the x axis, we have the Point $Point = (1, 0, 0)$, by rotating it of $\theta = 90°$ and getting $P_T = (0, 1, 0)$ 
&rarr; This rotation R_00 otates P to 90° counterclockwise (thats why we getting from the X to the Y axis and not the -Y axis)
- The calculation is: 
 
$$
P_T.x = P.x * R_00 + P.y * R_10 + P.z * R_20 \cr 
P_T.y = P.x * R_01 + P.y * R_11 + P.z * R_21 \cr 
P_T.z = P.x * R_02 + P.y * R_12 + P.z * R_22 \cr 
$$

- Cosine and sine can be used to determine the coordinates of a point on both axises
&rarr; for a point on the unit circle, its x and y coordinates with the cosine and sine of the angle $\theta$, respectively: 

$$
x = cos(\theta) = 0
y = sin(\theta) = 1 
given\theta = \frac{\pi}{2} -> same as 90°
$$

- The matrices for rotaion around the x and y axes can be derived similary with $R_x$ affecting rotation in the yz plane and $R_y$ in the xz plane. Those are the matrices **for right handed and row-major matrices** (completly different formula when using a different system). We are transforming a point via $\dot{v} = vR$ and not $\dot{v} = Rv$. There is no right and wrong here, but its the most used one:

$$
R_x(\theta) = \begin{bmatrix} 1 & 0 & 0 \cr 0 & cos(\theta) & sin(\theta) \cr 0 & -sin(\theta) & cos(\theta) \end{bmatrix}
R_y(\theta) = \begin{bmatrix} cos(\theta) & 0 & -sin(\theta) \cr 0 & 1 & 0 \cr 0 & sin(\theta) & cos(\theta) \end{bmatrix}
R_z(\theta) = \begin{bmatrix} cos(\theta) & sin(\theta)& 0\cr -sin(\theta) & cos(\theta) & 0 \cr 0 & 0 & 1 \end{bmatrix}
$$

#### Orthognal Matrices 
- The key attribute of orthogonal matrices is, that the transpose of an orthogonal matrix equals its inverse
$$
Q^T = Q^-1 <=> QQ^T ? I
$$
- I is the Identity matrix!
#### Vector transformation
- Vectors dont require translation (because their position is meaningless), we only focus on their magnitude and direction
```cpp
void multDirMatrix(const Vec3<T> &src, Vec3<T> &dst) const {
    dst.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0];
    dst.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1];
    dst.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2];
}
``` 
#### Matrix transpose operation
- The transpose of a matrix, denoted as $M^T$, is derived by flipping the matrix M over its main diagonal, effectifly transoforming the rows of M into columns of $M^T$
### Trigonometric Functions
- Sine and cosine are typically defined with respect to the unit circle, a circ
