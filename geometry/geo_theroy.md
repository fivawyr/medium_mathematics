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
- 
