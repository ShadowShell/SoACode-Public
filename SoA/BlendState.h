#pragma once

enum BlendEquationMode {
    BLEND_EQUATION_MODE_FUNC_ADD = GL_FUNC_ADD,
    BLEND_EQUATION_MODE_FUNC_REVERSE_SUBTRACT = GL_FUNC_REVERSE_SUBTRACT,
    BLEND_EQUATION_MODE_FUNC_SUBTRACT = GL_FUNC_SUBTRACT,
    BLEND_EQUATION_MODE_MAX = GL_MAX,
    BLEND_EQUATION_MODE_MIN = GL_MIN
};
enum BlendingFactorSrc {
    BLENDING_FACTOR_SRC_CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
    BLENDING_FACTOR_SRC_CONSTANT_COLOR = GL_CONSTANT_COLOR,
    BLENDING_FACTOR_SRC_DST_ALPHA = GL_DST_ALPHA,
    BLENDING_FACTOR_SRC_DST_COLOR = GL_DST_COLOR,
    BLENDING_FACTOR_SRC_ONE = GL_ONE,
    BLENDING_FACTOR_SRC_ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA,
    BLENDING_FACTOR_SRC_ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
    BLENDING_FACTOR_SRC_ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
    BLENDING_FACTOR_SRC_ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
    BLENDING_FACTOR_SRC_ONE_MINUS_SRC_1_ALPHA = GL_ONE_MINUS_SRC1_ALPHA,
    BLENDING_FACTOR_SRC_ONE_MINUS_SRC_1_COLOR = GL_ONE_MINUS_SRC1_COLOR,
    BLENDING_FACTOR_SRC_ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
    BLENDING_FACTOR_SRC_ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
    BLENDING_FACTOR_SRC_SRC_1_ALPHA = GL_SRC1_ALPHA,
    BLENDING_FACTOR_SRC_SRC_1_COLOR = GL_SRC1_COLOR,
    BLENDING_FACTOR_SRC_SRC_ALPHA = GL_SRC_ALPHA,
    BLENDING_FACTOR_SRC_SRC_ALPHA_SATURATE = GL_SRC_ALPHA_SATURATE,
    BLENDING_FACTOR_SRC_SRC_COLOR = GL_SRC_COLOR,
    BLENDING_FACTOR_SRC_ZERO = GL_ZERO
};
enum BlendingFactorDest {
    BLENDING_FACTOR_DEST_CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
    BLENDING_FACTOR_DEST_CONSTANT_COLOR = GL_CONSTANT_COLOR,
    BLENDING_FACTOR_DEST_DST_ALPHA = GL_DST_ALPHA,
    BLENDING_FACTOR_DEST_DST_COLOR = GL_DST_COLOR,
    BLENDING_FACTOR_DEST_ONE = GL_ONE,
    BLENDING_FACTOR_DEST_ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA,
    BLENDING_FACTOR_DEST_ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
    BLENDING_FACTOR_DEST_ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
    BLENDING_FACTOR_DEST_ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
    BLENDING_FACTOR_DEST_ONE_MINUS_SRC_1_ALPHA = GL_ONE_MINUS_SRC1_ALPHA,
    BLENDING_FACTOR_DEST_ONE_MINUS_SRC_1_COLOR = GL_ONE_MINUS_SRC1_COLOR,
    BLENDING_FACTOR_DEST_ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
    BLENDING_FACTOR_DEST_ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
    BLENDING_FACTOR_DEST_SRC_1_ALPHA = GL_SRC1_ALPHA,
    BLENDING_FACTOR_DEST_SRC_1_COLOR = GL_SRC1_COLOR,
    BLENDING_FACTOR_DEST_SRC_ALPHA = GL_SRC_ALPHA,
    BLENDING_FACTOR_DEST_SRC_ALPHA_SATURATE = GL_SRC_ALPHA_SATURATE,
    BLENDING_FACTOR_DEST_SRC_COLOR = GL_SRC_COLOR,
    BLENDING_FACTOR_DEST_ZERO = GL_ZERO
};

class BlendFunction {
public:
    BlendFunction(BlendEquationMode bem, BlendingFactorSrc bfs, BlendingFactorDest bfd);

    BlendEquationMode blendMode;
    BlendingFactorSrc blendFactorSrc;
    BlendingFactorDest blendFactorDest;
};


class BlendState {
public:
    BlendState(BlendFunction funcRGB, BlendFunction funcAlpha);

    void set() const;

    BlendFunction blendFuncRGB;
    BlendFunction blendFuncAlpha;
};