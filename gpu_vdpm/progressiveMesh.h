#ifndef __PROGRESSIVEMESH_H_INCLUDED__
#define __PROGRESSIVEMESH_H_INCLUDED__

#include "glm-0.9.6.3\glm\glm\glm.hpp"
#include <vector>

//helloWorld
//first, let's define each element of the vertex tree structure
struct vertexTreeNode 
{
	int descendentLeaf;  //the index of the leaf node, the vt* in the paper
	int vp;  //the index of the parent in the tree structure, the vp in the paer
	int vt;
	int vu;

	//the normal of this vertex itself
	glm::vec3 normal;

	//information about the surrounding area of the vertex, these are used during the construction of the tree
	std::vector <int> neighborVertices;  //indices of the neighboring vertices AMONG THE CURRENT TREE in the current step of construction
	std::vector <int> neighborFaces;  //indices TO THE ORIGINAL FACE ARRAY

	//the rule 1 for bounding sphere
	float boundingSphereRadius;
	//the rule 2 for normals
	std::vector <glm::vec3> coveredNormals;
	float normalConeAlpha;
	float sinAlphaSquare;
	//the rule 3 for screen space error
	float muSqure;
	float deltaSquare;
};


#endif