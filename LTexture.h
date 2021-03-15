#include <SDL.h>
#include <stdio.h>


class LTexture{
    private:
        int mWidth;
        int mHeight;
        float scale;            // The scale of the rendered sprite
        SDL_Texture *texture;   // The texture (image) of the sprite sheet
        SDL_Renderer *renderer; // The renderer
    public:

        /**
        * Creates a LTexture.
        *
        * @param filename    The filename of the sprite sheet image
        * @param renderer    The renderer used for loading the sprite sheet
        * @return            The LTexture
        */
        LTexture *LTexture_create(const char *filename,
                                            SDL_Renderer* renderer);

        /**
        * Delete the LTexture.
        *
        * @param lTexture  The Texture to delete
        */
        void LTexture_delete(struct LTexture *lTexture);

        /**
        * Renders the LTexture.
        *
        * @param lTexture  The LTexture to render
        * @param x            The top-left corner x-coordinate for the render
        * @param y            The top-left corner y-coordinate for the render
        */
        void LTexture_render(struct LTexture *lTexture,
                                int x, int y);

};

