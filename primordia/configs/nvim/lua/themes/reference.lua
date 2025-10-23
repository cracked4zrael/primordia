
-- Dark Ember Theme for NvChad
-- Author: Azrael
-- Style: Warm dark with glowing ember highlights

local M = {}

M.base_30 = {
  white = "#E0E0E0",
  darker_black = "#0A0A0A",
  black = "#0F0F0F", -- nvim bg
  black2 = "#151515",
  one_bg = "#1A1A1A",
  one_bg2 = "#202020",
  one_bg3 = "#272727",
  grey = "#3D3D3D",
  grey_fg = "#505050",
  grey_fg2 = "#5E5E5E",
  light_grey = "#6B6B6B",
  red = "#FF5E5E",
  baby_pink = "#FF7A7A",
  pink = "#FF9E9E",
  line = "#1E1E1E", -- for lines like vertsplit
  green = "#C6D57E",
  vibrant_green = "#D9E582",
  nord_blue = "#FF0000",
  blue = "#81A1C1",
  yellow = "#FFD479",
  sun = "#FFB84C",
  purple = "#C792EA",
  dark_purple = "#FF0000",
  teal = "#4DB5BD",
  orange = "#FF7B00",
  cyan = "#6FC1E6",
  statusline_bg = "#131313",
  lightbg = "#1A1A1A",
  pmenu_bg = "#FF7B00",
  folder_bg = "#FF7B00",
}

M.base_16 = {
  base00 = "#0F0F0F",
  base01 = "#151515",
  base02 = "#1C1C1C",
  base03 = "#2A2A2A",
  base04 = "#3D3D3D",
  base05 = "#DADADA",
  base06 = "#E0E0E0",
  base07 = "#F5F5F5",
  base08 = "#FF7B00",
  base09 = "#FFB84C",
  base0A = "#FFD479",
  base0B = "#C6D57E",
  base0C = "#6FC1E6",
  base0D = "#81A1C1",
  base0E = "#C792EA",
  base0F = "#FF5E5E",
}

M.polish_hl = {
  Comment = { fg = "#6E6A86", italic = true },
  Keyword = { fg = "#FF7B00", bold = true },
  Identifier = { fg = "#FFD479" },
  Function = { fg = "#FFB84C" },
  String = { fg = "#C6D57E" },
  Type = { fg = "#81A1C1" },
  Number = { fg = "#FF9E9E" },
  Constant = { fg = "#FFB84C" },
}

M.type = "dark"

return M

