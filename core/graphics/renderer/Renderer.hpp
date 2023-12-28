//
// Created by Caleb on 12/28/2023.
//

#ifndef RENDERER_HPP
#define RENDERER_HPP



class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void render() = 0;
};


struct RendererConfig {
    const char* window_title;
    int window_height;
    int window_width;
    int window_x;
    int window_y;
    bool fullscreen;
    bool resizable;
};



#endif //RENDERER_HPP
