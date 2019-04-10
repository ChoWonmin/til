//
//  loadObj.hpp
//  Cartoon
//
//  Created by Wonmin Cho on 01/04/2019.
//  Copyright © 2019 Wonmin Cho. All rights reserved.
//

#ifndef loadObj_hpp
#define loadObj_hpp

bool loadOBJ(
             const char * path,
             std::vector<glm::vec3> & out_vertices,
             std::vector<glm::vec2> & out_uvs,
             std::vector<glm::vec3> & out_normals
);

#endif /* loadObj_hpp */
