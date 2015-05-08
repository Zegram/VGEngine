
#include "engine/game/textRenderSystem.h"
#include "engine/game/textComponent.h"
#include "engine/game/game.h"
#include "engine/graphics/shader.h"
#include "engine/graphics/opengl.h"
#include "engine/graphics/graphicsDevice.h"

using namespace vg;
using namespace vg::graphics;
using namespace std;

TextRenderSystem::TextRenderSystem()
{

}

TextRenderSystem::~TextRenderSystem()
{

}

void TextRenderSystem::update(std::vector<GameObject*> *gameObjects)
{
    Shader* shader = Game::getInstance()->getGraphics()->getShader();

    for (auto i = gameObjects->begin(); i != gameObjects->end(); i++)
    {
        TextComponent* text = (*i)->getComponent<TextComponent>();
		TransformComponent* transform = (*i)->getComponent<TransformComponent>();
        if (text != nullptr && transform != nullptr)
        {
			shader->useProgram();
			gl::activeTexture();
			gl::bindTexture(text->getTextureId());
            
			shader->setRotation(0.0f);
			shader->setSize(Vector2<int>(0, 0));
			shader->setLayer(transform->getLayer());

			string textString = text->getText();
			FT_GlyphSlot* glyph = text->getGlyph();
			float x = transform->getPosition().getX();
			float y = transform->getPosition().getY();
			float base = y;

			for (int i = 0; i < textString.size(); i++)
			{
				FT_UInt index = FT_Get_Char_Index((*glyph)->face, textString[i]);
				FT_Load_Glyph(*text->getFace(), index, FT_RENDER_MODE_NORMAL);
				FT_Render_Glyph(*glyph, FT_RENDER_MODE_NORMAL);
				gl::texImage2D((*glyph)->bitmap.width, (*glyph)->bitmap.rows, (*glyph)->bitmap.buffer, GL_ALPHA);

				y = base - (*glyph)->bitmap_top;
				shader->setPosition(Vector2<int>(x, y));
				shader->setSize(Vector2<int>((*glyph)->bitmap.width, (*glyph)->bitmap.rows));

				GraphicsDevice::draw(shader, text->getVertexBuffer(), text->getIndexBuffer());
				x += ((*glyph)->advance.x >> 6);
			}
			gl::bindTexture(0u);
			shader->unUseProgram();
        }
    }
}