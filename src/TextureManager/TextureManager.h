#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

/*



*/
class TextureManager
{
    public:
        static TextureManager* GetInstance(){
            return s_Instance = (s_Instance != nullptr)?s_Instance : new TextureManager();
        }

    private:
        TextureManager(){}
        static TextureManager* s_Instance;
};

#endif // TEXTUREMANAGER_H
