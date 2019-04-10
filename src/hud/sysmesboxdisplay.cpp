#include "sysmesboxdisplay.h"

#include "../impacto.h"
#include "../renderer2d.h"
#include "../game.h"
#include "../mem.h"
#include "../scriptvars.h"
#include "../profile/hud/sysmesboxdisplay.h"
#include "../profile/dialogue.h"

namespace Impacto {
namespace SysMesBoxDisplay {

using namespace Impacto::Profile::SysMesBoxDisplay;

int MessageCount;
ProcessedTextGlyph Messages[8][255];
float BoxOpacity = 0.0f;
SysMesBoxAnimState AnimState = Hidden;
static float BoxAnimCount = 0.0f;
static float BoxTopY = 0.0f;
static float BoxBottomY = 0.0f;
static float LineLength = 0.0f;
static float BoxHeight = 0.0f;
static float BoxProgressCount = 0.0f;
static int TextStartCount = 0;
static Animation FadeAnimation;

void Init() {
  Configure();
  FadeAnimation.DurationIn = FadeInDuration;
  FadeAnimation.DurationOut = FadeOutDuration;
}

void Update(float dt) {
  FadeAnimation.Update(dt);

  if (AnimState == Hiding) {
    BoxAnimCount -= AnimationSpeed * dt;
    if (BoxAnimCount <= 0.0f) {
      BoxAnimCount = 0.0f;
      AnimState = Hidden;
    }
  } else if (AnimState == Showing) {
    BoxAnimCount += AnimationSpeed * dt;
    if (BoxAnimCount >= ScrWork[SW_SYSMESANIMCTF]) {
      BoxAnimCount = ScrWork[SW_SYSMESANIMCTF];
      AnimState = Shown;
    }
  }

  ScrWork[SW_SYSMESANIMCTCUR] = std::floor(BoxAnimCount);

  if (AnimState != Hidden) {
    float linePosX = LinePositionXFirst;
    LineLength = LineWidthFirst;
    if (ScrWork[SW_SYSMESANIMCTCUR] > 1) {
      LineLength = LineWidthMultiplier * BoxAnimCount + LineWidthBase;
      linePosX = LinePositionX - LinePositionMultiplier * BoxAnimCount;
    }
    Line1.Bounds = RectF(linePosX + 1.0f, Line1SpriteY, LineLength + 2.0f,
                         LineSpriteHeight);
    Line2.Bounds = RectF(linePosX + 1.0f, Line2SpriteY, LineLength + 2.0f,
                         LineSpriteHeight);

    BoxProgressCount = BoxAnimCount - BoxDisplayStartCount;
    TextStartCount = 2 * MessageCount + 8;
    if (BoxProgressCount >= TextStartCount) {
      BoxHeight = BoxTextFontSize * MessageCount + BoxHeightBase;
    } else {
      BoxHeight = BoxHeightMultiplier * BoxProgressCount;
    }

    BoxTopY = BoxTopYBase - (BoxHeight / 2.0f);
    BoxBottomY = BoxTopY + BoxHeight;

    MessageLabel.Bounds =
        RectF(MessageLabelSpriteXBase -
                  (12 * (BoxProgressCount - 2 * MessageCount - 8)) + 1.0f,
              MessageLabelSpriteY,
              (12 * (BoxProgressCount - 2 * MessageCount - 8)) - 2.0f,
              MessageLabelSpriteHeight);

    if (BoxProgressCount > TextStartCount) {
      if (AnimState == Showing && FadeAnimation.IsOut())
        FadeAnimation.StartIn();
      else if (AnimState == Hiding && FadeAnimation.IsIn())
        FadeAnimation.StartOut();
    }
  }
}

void Render() {
  if (BoxOpacity) {
    glm::vec4 col(1.0f, 1.0f, 1.0f, glm::smoothstep(0.0f, 1.0f, BoxOpacity));

    if (BoxAnimCount > 9.0f) {
      Renderer2D::DrawRect(
          RectF(BoxDisplayX, BoxTopY - 1.0f, BoxWidth, BoxHeight + 2.0f),
          glm::vec4(1.0f, 1.0f, 1.0f, 0.75f));
      Renderer2D::DrawSprite(BoxDecorationTop,
                             glm::vec2(BoxDisplayX, BoxTopY - 3.0f), col);
      Renderer2D::DrawSprite(BoxDecorationBottom,
                             glm::vec2(BoxDisplayX, BoxBottomY - 3.0f), col);

      if (BoxProgressCount > TextStartCount) {
        glm::vec4 texCol(1.0, 1.0f, 1.0f, FadeAnimation.Progress);
        if (BoxHeight > 56) {
          Renderer2D::DrawSprite(
              TextDecoration, glm::vec2(BoxDisplayX, BoxTopY + 36.0f), texCol);
          Renderer2D::DrawSprite(TextDecoration,
                                 glm::vec2(BoxDisplayX, BoxBottomY - 32.0f),
                                 texCol);
        }
        Renderer2D::DrawSprite(MessageLabel,
                               glm::vec2(BoxDisplayX, BoxTopY + 3.0f), texCol);

        // TODO: Draw Yes/No/OK buttons here

        float textBeginY = TextMiddleY - (TextMarginY * (4 + MessageCount));
        for (int i = 0; i < MessageCount; i++) {
          int lineLen;
          for (lineLen = 0; lineLen < 255; lineLen++) {
            if (Messages[i][lineLen].CharId == 0) break;
            Messages[i][lineLen].DestRect.Y = textBeginY + (i * TextLineHeight);
          }
          Renderer2D::DrawProcessedText(
              Messages[i], lineLen, Profile::Dialogue::DialogueFont, texCol.a);
        }
      }

    } else {
      Renderer2D::DrawSprite(
          Line1,
          glm::vec2(LineDisplayXBase - (LineLength / 2.0f), Line1DisplayY),
          col);
      Renderer2D::DrawSprite(
          Line2,
          glm::vec2(LineDisplayXBase - (LineLength / 2.0f), Line2DisplayY),
          col);
    }
  }
}

}  // namespace SysMesBoxDisplay
}  // namespace Impacto