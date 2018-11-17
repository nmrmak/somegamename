#ifndef FUNWITHKRLE_IDRAWABLE_H
#define FUNWITHKRLE_IDRAWABLE_H


class IDrawable {
public:
    virtual void draw(std::shared_ptr<ICanvas> &canvas) = 0;
};


#endif //FUNWITHKRLE_IDRAWABLE_H
