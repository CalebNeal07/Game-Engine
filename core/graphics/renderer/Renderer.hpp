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



#endif //RENDERER_HPP
