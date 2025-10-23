-- Az Black & White (safe Base46-compatible version)

local M = {}

M.base_30 = {
  white = "#FFFFFF",
  black = "#000000",
  darker_black = "#000000",
  black2 = "#0A0A0A",
  grey = "#2A2A2A",
  grey_fg = "#FF0000",
  grey_fg2 = "#505050",
  light_grey = "#6B6B6B",

  red = "#6392c1",
  green = "#B5B5B5",
  blue = "#FF0000",
  yellow = "#CAA9FA",
  orange = "#999999",
  purple = "#BBBBBB",
  cyan = "#d6bfff",
  pink = "#D0D0D0",
  teal = "#AAAAAA",
  nord_blue = "#FFFFFF";
  dark_purple = "#FF0000";

  line = "#1A1A1A",
  folder_bg = "#BBBBBB",
  pmenu_bg = "#555555",
  statusline_bg = "#0A0A0A",
  lightbg = "#111111",
}

M.base_16 = {
  base00 = "#000000",
  base01 = "#0A0A0A",
  base02 = "#111111",
  base03 = "#151515",
  base04 = "#2A2A2A",
  base05 = "#FFFFFF",
  base06 = "#FF0000",
  base07 = "#FFFFFF",
  base08 = "#bd93f9",
  base09 = "#AAAAAA",
  base0A = "#CCCCCC",
  base0B = "#CC0000",
  base0C = "#BBBBBB",
  base0D = "#999999",
  base0E = "#FF0000",
  base0F = "#FF0000",
}

M.polish_hl = {
  Comment = { fg = "#555555", italic = true },
  Normal = { fg = "#FFFFFF", italic = true },
  Keyword = { fg = "#BBBBBB", bold = true },
  Function = { fg = "#CCCCCC", bold = true },
  Identifier = { fg = "#DDDDDD" },
  String = { fg = "#E0E0E0" },
  Type = { fg = "#B0B0B0" },
  Constant = { fg = "#C0C0C0" },
  Number = { fg = "#D0D0D0" },
  Operator = { fg = "#999999" },
}

M.type = "dark"

return M

