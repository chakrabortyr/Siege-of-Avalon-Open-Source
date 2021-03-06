unit AniDec30;

{$MODE Delphi}

{******************************************************************************}
{                                                                              }
{               Siege Of Avalon : Open Source Edition                          }
{               -------------------------------------                          }
{                                                                              }
{ Portions created by Digital Tome L.P. Texas USA are                          }
{ Copyright ©1999-2000 Digital Tome L.P. Texas USA                             }
{ All Rights Reserved.                                                         }
{                                                                              }
{ Portions created by Team SOAOS are                                           }
{ Copyright (C) 2003 - Team SOAOS.                                             }
{                                                                              }
{                                                                              }
{ Contributor(s)                                                               }
{ --------------                                                               }
{ Dominique Louis <Dominique@SavageSoftware.com.au>                            }
{                                                                              }
{                                                                              }
{                                                                              }
{ You may retrieve the latest version of this file at the SOAOS project page : }
{   http://www.sourceforge.com/projects/soaos                                  }
{                                                                              }
{ The contents of this file maybe used with permission, subject to             }
{ the GNU Lesser General Public License Version 2.1 (the "License"); you may   }
{ not use this file except in compliance with the License. You may             }
{ obtain a copy of the License at                                              }
{ http://www.opensource.org/licenses/lgpl-license.php                          }
{                                                                              }
{ Software distributed under the License is distributed on an                  }
{ "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or               }
{ implied. See the License for the specific language governing                 }
{ rights and limitations under the License.                                    }
{                                                                              }
{ Description                                                                  }
{ -----------                                                                  }
{                                                                              }
{                                                                              }
{                                                                              }
{                                                                              }
{                                                                              }
{                                                                              }
{                                                                              }
{ Requires                                                                     }
{ --------                                                                     }
{   DirectX Runtime libraris on Win32                                          }
{   They are available from...                                                 }
{   http://www.microsoft.com.                                                  }
{                                                                              }
{ Programming Notes                                                            }
{ -----------------                                                            }
{                                                                              }
{                                                                              }
{                                                                              }
{                                                                              }
{ Revision History                                                             }
{ ----------------                                                             }
{   July    13 2003 - DL : Initial Upload to CVS                               }
{                                                                              }
{******************************************************************************}

interface

uses
  LCLIntf, LCLType,
  Classes,
  Graphics,
  SysUtils,
  Controls;


const
  MaxItems = 2047;
  MaxTiles = 2047;
  ItemListSize = 32767;
  MaxScripts = 128;
  MaxScriptFrames = 64;
  MaxZones = 255;
  MaxLightStates = 4;
  WorkWidth = 384;
  WorkHeight = 160;
  MaxSubMaps = 127;
  MaxZoneHeight = 2048;

type
  PGridInfo = ^GridInfo;
  GridInfo = packed record
    Figure : Pointer; //For collision detection
    FilterID : Smallint;
    TriggerID : Smallint;
    CollisionMask : Word;
    LineOfSightMask : Word;
    FilterMask : Word;
    TriggerMask : Word;
    Tile : array[ 0..4 ] of Word;
    Zone : array[ 0..4 ] of Byte;
    BitField : Byte; //Bit 7 denotes a diamond tile, Bit 6 is automap.
  end;

  PTileInfo = ^TileInfo;
  TileInfo = packed record
    ImageIndex : Word;
    Rows : Word;
    Columns : Word;
    Zone : Word;
    Element : Byte;
    Reserved : Byte;
  end;

  MapColumnHeaderInfo = packed record
    BaseLine : Longint;
    Top : Longint;
    Active : Boolean;
    Reserved : Byte;
  end;

  RowUpdateInfo = packed record
    Figure : Pointer; //The first figure on the row
    OverlapRow : Longint; //The last row that contains an item which could overlap this row
    DescendRow : Longint; //The first row which has an item that descends below its position to this row
    MaxHeight : Longint; //The tallest item on this row
    ItemIndex : Word; //The first item on the row
  end;

  PItemInfo = ^ItemInfo;
  ItemInfo = packed record
    Top : Longint;
    Left : Longint;
    Slope : Single;
    StripHeights : HGLOBAL;
    CollisionMasks : HGLOBAL;
    LineOfSightMasks : HGLOBAL;
    LightPoints : HGLOBAL;
    Width : Word;
    Height : Word;
    Strips : Word; //=roundup(Width/TileWidth)  Strips*Height=next Items top
    StripCount : Word;
    Used : Boolean;
    Visible : Boolean;
    AutoTransparent : Boolean;
    Vertical : Boolean;
  end;

  PItemInstanceInfo = ^ItemInstanceInfo;
  ItemInstanceInfo = packed record
    X : Longint;
    Y : Longint;
    ImageY : Word;
    Slope0 : Single;
    Slope1 : Single;
    Slope2 : Single;
    RefItem : word;
    FilterID : Smallint;
    XRayID : Smallint;
    ImageX : Word;
    Width : Word;
    Height : Word;
    VHeight : Word; //Height of region that may obscure objects behind it
    Next : Word;
    Zone : Word;
    AutoTransparent : Boolean;
    Visible : Boolean;
    Last : Boolean;
    Vertical : Boolean;
  end;

  ScriptInfo = packed record
    Frames : Word;
    FrameID : array[ 1..MaxScriptFrames ] of Word;
    Name : string[ 32 ];
    Multiplier : Word;
    Tag : Longint;
  end;

  BITMAP = record
    bmType : Longint;
    bmWidth : Longint;
    bmHeight : Longint;
    bmWidthBytes : Longint;
    bmPlanes : Integer;
    bmBitsPixel : Integer;
    bmBits : Pointer;
  end;

  TPixelFormat = ( pf555, pf565, pf888 );


function Min( A, B : Single ) : Single;
function ATan( X, Y : Single ) : Single;
procedure Clip( ClipX1, ClipX2 : Integer; var DestX1, DestX2, SrcX1, SrcX2 : Integer );
procedure Clip1( ClipX1, ClipX2 : Integer; var DestX1, SrcX1, SrcX2 : Integer );
procedure Clip2( ClipX1, ClipX2 : Integer; var DestX1, SrcX1, W : Integer );

implementation

function Min( A, B : Single ) : Single;
begin
  if ( A < B ) then
    Result := A
  else
    Result := B;
end;

function ATan( X, Y : Single ) : Single;
begin
  if ( X = 0 ) then
  begin
    if ( Y >= 0 ) then
      Result := PI / 2
    else
      Result := 3 * PI / 2;
  end
  else if ( X > 0 ) then
  begin
    if ( Y >= 0 ) then
      Result := ArcTan( Y / X )
    else
      Result := ArcTan( Y / X ) + 2 * PI;
  end
  else
  begin
    Result := ArcTan( Y / X ) + PI;
  end;
  if Result < 0 then
    Result := Result + 2 * PI;
end;

procedure Clip( ClipX1, ClipX2 : Integer; var DestX1, DestX2, SrcX1, SrcX2 : Integer );
begin
  if ( DestX1 < ClipX1 ) then
  begin
    Inc( SrcX1, ClipX1 - DestX1 );
    DestX1 := ClipX1;
  end;
  if ( DestX2 > ClipX2 ) then
  begin
    Dec( SrcX2, DestX2 - ClipX2 );
    DestX2 := ClipX2;
  end;
end;

procedure Clip1( ClipX1, ClipX2 : Integer; var DestX1, SrcX1, SrcX2 : Integer );
begin
  if ( DestX1 < ClipX1 ) then
  begin
    Inc( SrcX1, ClipX1 - DestX1 );
    DestX1 := ClipX1;
  end;
  if ( DestX1 + ( SrcX2 - SrcX1 ) > ClipX2 ) then
  begin
    SrcX2 := SrcX1 + ClipX2 - DestX1;
  end;
end;

procedure Clip2( ClipX1, ClipX2 : Integer; var DestX1, SrcX1, W : Integer );
begin
  if ( DestX1 < ClipX1 ) then
  begin
    Dec( W, ClipX1 - DestX1 );
    Inc( SrcX1, ClipX1 - DestX1 );
    DestX1 := ClipX1;
  end;
  if ( DestX1 + W > ClipX2 ) then
  begin
    W := ClipX2 - DestX1;
  end;
end;

end.
