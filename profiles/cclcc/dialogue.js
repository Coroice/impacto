root.Sprites["ADVBox"] = {
    Sheet: "MesBox",
    Bounds: { X: 0, Y: 1, Width: 1920, Height: 298 }
};

root.Sprites["ADVBoxMask"] = {
    Sheet: "MesBox",
    Bounds: { X: 0, Y: 301, Width: 1920, Height: 298 }
};

root.Sprites["WaitIconSpriteFixed"] = {
    Sheet: "Data",
    Bounds: { X: 1977, Y: 937, Width: 126, Height: 95 },
};

root.Dialogue = {
    REVBounds: { X: 0, Y: 0, Width: 960, Height: 400 },
    REVNameFontSize: 24,
    REVNameColor: 24,
    REVNameOffset: 34,
    NVLBounds: { X: 188, Y: 128, Width: 1536, Height: 600 },
    ADVBounds: { X: 330, Y: 815, Width: 1440, Height: 270 },
    ADVBoxSprite: "ADVBox",
    ADVBoxMask: "ADVBoxMask",
    ADVBoxNamePlateMainSprites: [],
    ADVBoxNamePlateLabelSprites: [],
    ADVBoxNamePlateMainPos: { X: 0, Y: 780 },
    ADVBoxNamePlateLabelPos: { X: 0, Y: 998 },
    ADVBoxShowName: false,
    ADVBoxNamePlateCount: 47,
    ADVBoxEffectDuration: 10,
    ADVBoxPos: { X: 0, Y: 760 },
    FadeOutDuration: 0.33,
    FadeInDuration: 0.33,
    DialogueBoxCurrentType: DialogueBoxType.CC,
    NVLBoxMaxOpacity: 0.55,
    ADVNameAlignment: TextAlignment.Left,
    ADVNameFontSize: 33,
    ADVNamePos: { X: 173, Y: 773 },
    WaitIconCurrentType: WaitIconType.SpriteAnimFixed,
    WaitIconSpriteAnim: "WaitIconSpriteAnim",
    WaitIconSprite: "WaitIconSpriteFixed",
    WaitIconAnimationDuration: 0.7,
    WaitIconOffset: { X: 1624, Y: 955 },
    DialogueFont: "Default",
    DefaultFontSize: 36,
    RubyFontSize: 21,
    RubyYOffset: -27,
    ColorTable: [
        [0xFFFFFF, 0x000000], [0x5080FF, 0x000000],
        [0xFF7080, 0x000000], [0xFFA0F8, 0x000000],
        [0x46FF80, 0x000000], [0x90FFFF, 0x000000],
        [0xFFFF70, 0x000000], [0x80FFC0, 0x000000],
        [0xFFB080, 0x000000], [0xB080FF, 0x000000],
        [0x000000, 0x808080], [0x000000, 0x5080FF],
        [0x000000, 0xFF7080], [0x000000, 0xFFA0F8],
        [0x000000, 0x268840], [0x000000, 0x409999],
        [0x000000, 0x888830], [0x000000, 0x80FFC0],
        [0x000000, 0xFFB080], [0x000000, 0xB080FF],
        [0xD0D0D0, 0x000000], [0xD0D0FF, 0x000000],
        [0xFFD0D0, 0x000000], [0xFFD0FF, 0x000000],
        [0xD0FFD0, 0x000000], [0xD0FFFF, 0x000000],
        [0xFFFFD0, 0x000000], [0xE8FFD0, 0x000000],
        [0xFFE8D0, 0x000000], [0xD0E8FF, 0x000000],
        [0xFFFFFF, 0x808080], [0xFFFFFF, 0x5080FF],
        [0xFFFFFF, 0xFF7080], [0xFFFFFF, 0xFFA0F8],
        [0xFFFFFF, 0x46FF80], [0xFFFFFF, 0x90FFFF],
        [0xFFFFFF, 0xFFFF70], [0xFFFFFF, 0x80FFC0],
        [0xFFFFFF, 0xFFB080], [0xFFFFFF, 0xB080FF],
        [0xFFEEEE, 0x000000], [0xFFCCCC, 0x000000],
        [0xFFAAAA, 0x000000], [0xFF9999, 0x000000],
        [0xFF8888, 0x000000], [0xFFFF00, 0x000000],
        [0xFEF000, 0x000000], [0xFF7777, 0x000000],
        [0xFF6666, 0x000000], [0xFF5555, 0x000000],
        [0xFF4444, 0x000000], [0xFF3333, 0x000000],
        [0xFF2222, 0x000000], [0xFF0000, 0x000000],
        [0xDD0000, 0x000000], [0xBB0000, 0x000000],
        [0xB00000, 0x000000], [0xAA0000, 0x000000],
        [0x950000, 0x000000], [0x808080, 0x000000],
        [0xAAAAAA, 0x000000], [0xAAC1C9, 0x000000],
        [0x000000, 0x000000], [0x000000, 0x000000],
        [0x000000, 0x000000], [0x000000, 0x000000],
        [0x000000, 0x000000], [0xF80B0B, 0x000000],
        [0xF8910B, 0x000000], [0x33F12A, 0x000000]
    ],
    MaxPageSize: 2000,
    PageCount: 3,
    ColorTagIsUint8: false
};

MakeAnimation({
    Name: "WaitIconSpriteAnim",
    Sheet: "Data",
    FirstFrameX: 864, //1114
    FirstFrameY: 877,
    FrameWidth: 190,
    ColWidth: 216,
    FrameHeight: 185,
    RowHeight: 185,
    Frames: 10,
    Duration: 1,
    Rows: 1,
    Columns: 10,
    PrimaryDirection: AnimationDirections.Right
});

var namePlateMainX = 0;
var namePlateMainY = 0;
var namePlateLabelX = 3600;
var namePlateLabelY = 0;
var namePlateMainWidth = 448;
var namePlateMainHeight = 232;
var namePlateLabelWidth = 310;
var namePlateLabelHeight = 40;
for (var i = 1; i < 48; i++) {
    root.Sprites["ADVBoxNamePlateMain" + i] = {
        Sheet: "NamePlate",
        Bounds: {
            X: namePlateMainX,
            Y: namePlateMainY,
            Width: namePlateMainWidth,
            Height: namePlateMainHeight
        }
    };
    root.Dialogue.ADVBoxNamePlateMainSprites.push("ADVBoxNamePlateMain" + i);

    if (i % 8 == 0) {
        namePlateMainY += namePlateMainHeight;
        namePlateMainX = 0;
    }
    else {
        namePlateMainX += namePlateMainWidth;
    }

    root.Sprites["ADVBoxNamePlateLabel" + i] = {
        Sheet: "NamePlate",
        Bounds: {
            X: namePlateLabelX,
            Y: namePlateLabelY,
            Width: namePlateLabelWidth,
            Height: namePlateLabelHeight
        }
    };
    root.Dialogue.ADVBoxNamePlateLabelSprites.push("ADVBoxNamePlateLabel" + i);

    namePlateLabelY += namePlateLabelHeight;
}

include('cclcc/nametag.js');