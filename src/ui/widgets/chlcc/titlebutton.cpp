#include "titlebutton.h"

#include "../../../renderer2d.h"
#include "../../../profile/games/chlcc/titlemenu.h"

namespace Impacto {
namespace UI {
namespace Widgets {
namespace CHLCC {

using namespace Impacto::Profile::CHLCC::TitleMenu;

void TitleButton::Render() {
  glm::vec4 black(0.0f);
  black.a = Opacity;
  glm::vec4 white(1.0f);
  white.a = Opacity;

  if (HasFocus) {
    if (TitleButton::Id < 4) {
    Renderer2D::DrawSprite(HighlightSprite,
                           glm::vec2(Bounds.X - ItemHighlightOffsetX,
                                     Bounds.Y - ItemHighlightOffsetY),
                           white);
    Renderer2D::DrawSprite(FocusedSprite,
                           glm::vec2(Bounds.X, Bounds.Y),
                           white);
    } else {
      Renderer2D::DrawSprite(
          HighlightSprite,
          glm::vec2(SecondaryItemHighlightX, Bounds.Y - ItemHighlightOffsetY),
          white);
      Renderer2D::DrawSprite(FocusedSprite, glm::vec2(Bounds.X, Bounds.Y),
                             white);
      switch (TitleButton::Id) {
        case 4: {  //Load to Load line
          Renderer2D::DrawSprite(
              ItemUpLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuLoadLineY), white);
        } break;
        case 5: {  //Load to Quick Load line
          Renderer2D::DrawSprite(
              ItemStraightLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuLoadQuickLineY),
              white);
        } break;
        case 6: {  // Extra to Clear List line
          Renderer2D::DrawSprite(
              ItemHyperUpLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuExtraClearY), white);
        } break;
        case 7: {  // Extra to CG Library line
          Renderer2D::DrawSprite(
              ItemSuperUpLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuExtraCGY), white);
        } break;
        case 8: {  // Extra to Sound Library line
          Renderer2D::DrawSprite(
              ItemUpLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuExtraSoundY), white);
        } break;
        case 9: {  // Extra to Movie Library line
          Renderer2D::DrawSprite(
              ItemStraightLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuExtraMovieY), white);          
        } break;
        case 10: {  // Extra to Tips line
          Renderer2D::DrawSprite(
              ItemDownLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuExtraTipsY), white);
        } break;
        case 11: {  // Extra to Trophy line
          Renderer2D::DrawSprite(
              ItemSuperDownLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuExtraTrophyY), white);
        } break;
        case 12: {  // System to Config line 
          Renderer2D::DrawSprite(
              ItemUpLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuSystemConfigY), white);
        } break;
        case 13: {  // System to System Save line 
          Renderer2D::DrawSprite(
              ItemStraightLine,
              glm::vec2(SecondaryMenuLineX, SecondaryMenuSystemSaveY), white);
        } break;
      }
    }
  } else {
    if (Enabled) {
      Renderer2D::DrawSprite(NormalSprite, glm::vec2(Bounds.X, Bounds.Y),
                             white);
    } else {
      Renderer2D::DrawSprite(DisabledSprite, glm::vec2(Bounds.X, Bounds.Y),
                             white);
    }
  }
}

}  // namespace CHLCC
}  // namespace Widgets
}  // namespace UI
}  // namespace Impacto