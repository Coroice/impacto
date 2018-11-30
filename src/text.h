#pragma once

#include "font.h"
#include "animation.h"
#include "vm/thread.h"
#include <enum.h>

namespace Impacto {

BETTER_ENUM(TextAlignment, int, Left = 0, Center, Right)

BETTER_ENUM(CharacterTypeFlags, uint8_t, Space = (1 << 0),
            WordStartingPunct = (1 << 1), WordEndingPunct = (1 << 2))

// TODO: think about / profile memory access patterns

struct DialogueColorPair {
  uint32_t TextColor;
  uint32_t OutlineColor;
};

struct ProcessedTextGlyph {
  DialogueColorPair Colors;
  Sprite Glyph;
  float Opacity;
  RectF DestRect;
  uint8_t CharacterType;
};

enum DialoguePageMode : uint8_t { DPM_ADV = 0, DPM_NVL = 1 };

int const DialogueMaxNameLength = 32;
int const DialogueMaxRubyChunks = 32;
int const DialogueMaxRubyChunkLength = 32;

struct DialoguePageFeatureConfig {
  RectF NVLBounds;
  RectF ADVBounds;
  TextAlignment ADVNameAlignment = TextAlignment::Left;
  float ADVNameFontSize;
  glm::vec2 ADVNamePos;
  float DefaultFontSize;
  float RubyFontSize;
  Font DialogueFont;
  DialogueColorPair ColorTable[70];
  SpriteSheet DataSpriteSheet;
};

extern DialoguePageFeatureConfig const DialoguePageFeatureConfig_RNE;

struct RubyChunk {
  int FirstBaseCharacter;
  int Length;
  uint16_t Text[DialogueMaxRubyChunkLength];
};

struct DialoguePage {
  static void Init();

  int Id;

  Animation FadeAnimation;

  int Length;
  int FullyOpaqueGlyphCount;
  bool TextIsFullyOpaque;

  int NameLength;
  bool HasName;
  uint16_t Name[DialogueMaxNameLength];

  int RubyChunkCount;
  int CurrentRubyChunk;
  RubyChunk RubyChunks[DialogueMaxRubyChunks];

  float CurrentX;
  float CurrentY;

  ProcessedTextGlyph* Glyphs;

  DialoguePageMode Mode;

  bool NVLResetBeforeAdd;
  bool AutoForward;

  void Clear();
  void AddString(Vm::Sc3VmThread* ctx);
  void Update(float dt);
  void Render();
};

extern DialoguePage* DialoguePages;

int TextGetStringLength(Vm::Sc3VmThread* ctx);

}  // namespace Impacto