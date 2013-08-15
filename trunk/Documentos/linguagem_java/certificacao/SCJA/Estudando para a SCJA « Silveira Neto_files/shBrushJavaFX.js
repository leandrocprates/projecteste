/* 
  *  A very primitive JavaFX Brush for Syntax Highlighter
  * Written by Coffeejolts
  * July 28, 2008
  */

dp.sh.Brushes.JavaFX = function()
{
	var keywords = 	'abstract assert attribute bind break ' +
					'class continue delete false for ' +
					'function if import init insert ' +
					'let new not null package ' +
					'private protected public readonly return ' +
					'super sizeof static this throw ' +
					'try true var while after ' +
					'and as before by catch ' +
					'do dur else exclusive extends ' +
					'finally first from in bound ' +
					'indexof into inverse lazy last ' +
					'on or replace step typeof ' +
					'with where instanceof override at ' +
					'then tween mod';

	this.regexList = [
		{ regex: dp.sh.RegexLib.SingleLineCComments,							css: 'comment' },		// one line comments
		{ regex: dp.sh.RegexLib.MultiLineCComments,								css: 'comment' },		// multiline comments
		{ regex: dp.sh.RegexLib.DoubleQuotedString,								css: 'string' },		// strings
		{ regex: dp.sh.RegexLib.SingleQuotedString,								css: 'string' },		// strings
		{ regex: new RegExp('\\b([\\d]+(\\.[\\d]+)?|0x[a-f0-9]+)\\b', 'gi'),	css: 'number' },		// numbers		
		{ regex: new RegExp(this.GetKeywords(keywords), 'gm'),					css: 'keyword' }		// java keyword
		];

	this.CssClass = 'dp-j';
	this.Style =	'.dp-j .annotation { color: #646464; }' +
					'.dp-j .number { color: #C00000; }';
}

dp.sh.Brushes.JavaFX.prototype	= new dp.sh.Highlighter();
dp.sh.Brushes.JavaFX.Aliases	= ['jfx'];
