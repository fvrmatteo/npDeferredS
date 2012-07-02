#include "npShadowMapMeshRenderer.h"
#include "npProgramLoader.h"
void npShadowMapMeshRenderer::setup()
{
    npProgramLoader pl;
    program = pl.loadProgram ("ShadowShaderMesh");

    glBindAttribLocation(program,ATTRIB_VERTEX,"position");
  
 
    pl.linkProgram();
    glUseProgram(program);
    
    uObjectMatrix = glGetUniformLocation(program,"objectMatrix");
	uWorldMatrix = glGetUniformLocation(program,"worldMatrix");
    uLightProjectionMatrix = glGetUniformLocation(program,"lightProjectionMatrix");
	

 

    glUseProgram(0);
}


void npShadowMapMeshRenderer::start(const npCamera &cam)
{
    glUseProgram(program);

    glUniformMatrix4fv(uLightProjectionMatrix , 1, 0,   cam.lightMatrix1.getPtr());
	  glUniformMatrix4fv(uWorldMatrix , 1, 0,   cam.worldMatrix.getPtr());
    glEnableVertexAttribArray(ATTRIB_VERTEX);
 
    

}
void npShadowMapMeshRenderer::draw(const npMesh *mesh)
{
	


    glBindBuffer(GL_ARRAY_BUFFER,mesh->vertexBuffer);
 
	
    glVertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, sizeof(float) * mesh->stride,(GLvoid*) (sizeof(float) * 0));
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,  mesh->indexBuffer);
	if (mesh->isMultiObject)
	{

		for(int i=0; i<mesh->objectMatrices.size();i++ ){

			glUniformMatrix4fv(uObjectMatrix, 1, 0, mesh->objectMatrices[i].getPtr());
			glDrawElements(GL_TRIANGLES,mesh->numIndices , GL_UNSIGNED_INT, (void*)0);
		}
	
	
	}else
	{
	
		glUniformMatrix4fv(uObjectMatrix, 1, 0,  mesh->objectMatrix.getPtr());
		glDrawElements(GL_TRIANGLES,mesh->numIndices , GL_UNSIGNED_INT, (void*)0);
	}
  



}
void npShadowMapMeshRenderer::stop()
{
    glDisableVertexAttribArray(ATTRIB_VERTEX);
   
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,  0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
	   glUseProgram(0);

}