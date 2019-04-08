# Graphics Pipeline
>  transforming all 3D coordinates to 2D pixels that fit on screen.
> processing cores to quickly process vertex data within the graphics pipeline by running small programs on the GPU.

### kind of render types (hint)
- GL_POINTS
- GL_TRIANGLES
- GL_LINE_STRIP

### Step
- Vertex Shader : Transform 3D coordinates into different 3D coordinates.
- Shape Assembly : Assemble all the points in the primitive shape given.
- Geometry Shader :  Generate other shapes by emitting new vertices to form new primitive.
- Rasterization : Clipping and maps the resulting primitive(s) to the corresponding pixels on the final screen.
- Fragment Shader : Calculate the final color of a pixel.
- Alpha test and Blending : Check if the resulting fragment is in front or behind other objects and should be discarded accordingly. Also checks for alpha values and blends the objects.