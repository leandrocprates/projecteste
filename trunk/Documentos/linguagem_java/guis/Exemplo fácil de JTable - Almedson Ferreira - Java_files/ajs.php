if(typeof org=="undefined"){var org=new Object();}if(typeof org.openx=="undefined"){org.openx=new Object();}if(typeof org.openx.util=="undefined"){org.openx.util=new Object();}if(typeof org.openx.SWFObjectUtil=="undefined"){org.openx.SWFObjectUtil=new Object();}org.openx.SWFObject=function(_1,id,w,h,_5,c,_7,_8,_9,_a){if(!document.getElementById){return;}this.DETECT_KEY=_a?_a:"detectflash";this.skipDetect=org.openx.util.getRequestParameter(this.DETECT_KEY);this.params=new Object();this.variables=new Object();this.attributes=new Array();if(_1){this.setAttribute("swf",_1);}if(id){this.setAttribute("id",id);}if(w){this.setAttribute("width",w);}if(h){this.setAttribute("height",h);}if(_5){this.setAttribute("version",new org.openx.PlayerVersion(_5.toString().split(".")));}this.installedVer=org.openx.SWFObjectUtil.getPlayerVersion();if(!window.opera&&document.all&&this.installedVer.major>7){org.openx.SWFObject.doPrepUnload=true;}if(c){this.addParam("bgcolor",c);}var q=_7?_7:"high";this.addParam("quality",q);this.setAttribute("useExpressInstall",false);this.setAttribute("doExpressInstall",false);var _c=(_8)?_8:window.location;this.setAttribute("xiRedirectUrl",_c);this.setAttribute("redirectUrl","");if(_9){this.setAttribute("redirectUrl",_9);}};org.openx.SWFObject.prototype={useExpressInstall:function(_d){this.xiSWFPath=!_d?"expressinstall.swf":_d;this.setAttribute("useExpressInstall",true);},setAttribute:function(_e,_f){this.attributes[_e]=_f;},getAttribute:function(_10){return this.attributes[_10];},addParam:function(_11,_12){this.params[_11]=_12;},getParams:function(){return this.params;},addVariable:function(_13,_14){this.variables[_13]=_14;},getVariable:function(_15){return this.variables[_15];},getVariables:function(){return this.variables;},getVariablePairs:function(){var _16=new Array();var key;var _18=this.getVariables();for(key in _18){_16[_16.length]=key+"="+_18[key];}return _16;},getSWFHTML:function(){var _19="";if(navigator.plugins&&navigator.mimeTypes&&navigator.mimeTypes.length){if(this.getAttribute("doExpressInstall")){this.addVariable("MMplayerType","PlugIn");this.setAttribute("swf",this.xiSWFPath);}_19="<embed type=\"application/x-shockwave-flash\" src=\""+this.getAttribute("swf")+"\" width=\""+this.getAttribute("width")+"\" height=\""+this.getAttribute("height")+"\" style=\""+this.getAttribute("style")+"\"";_19+=" id=\""+this.getAttribute("id")+"\" name=\""+this.getAttribute("id")+"\" ";var _1a=this.getParams();for(var key in _1a){_19+=[key]+"=\""+_1a[key]+"\" ";}var _1c=this.getVariablePairs().join("&");if(_1c.length>0){_19+="flashvars=\""+_1c+"\"";}_19+="/>";}else{if(this.getAttribute("doExpressInstall")){this.addVariable("MMplayerType","ActiveX");this.setAttribute("swf",this.xiSWFPath);}_19="<object id=\""+this.getAttribute("id")+"\" classid=\"clsid:D27CDB6E-AE6D-11cf-96B8-444553540000\" width=\""+this.getAttribute("width")+"\" height=\""+this.getAttribute("height")+"\" style=\""+this.getAttribute("style")+"\">";_19+="<param name=\"movie\" value=\""+this.getAttribute("swf")+"\" />";var _1d=this.getParams();for(var key in _1d){_19+="<param name=\""+key+"\" value=\""+_1d[key]+"\" />";}var _1f=this.getVariablePairs().join("&");if(_1f.length>0){_19+="<param name=\"flashvars\" value=\""+_1f+"\" />";}_19+="</object>";}return _19;},write:function(_20){if(this.getAttribute("useExpressInstall")){var _21=new org.openx.PlayerVersion([6,0,65]);if(this.installedVer.versionIsValid(_21)&&!this.installedVer.versionIsValid(this.getAttribute("version"))){this.setAttribute("doExpressInstall",true);this.addVariable("MMredirectURL",escape(this.getAttribute("xiRedirectUrl")));document.title=document.title.slice(0,47)+" - Flash Player Installation";this.addVariable("MMdoctitle",document.title);}}if(this.skipDetect||this.getAttribute("doExpressInstall")||this.installedVer.versionIsValid(this.getAttribute("version"))){var n=(typeof _20=="string")?document.getElementById(_20):_20;n.innerHTML=this.getSWFHTML();return true;}else{if(this.getAttribute("redirectUrl")!=""){document.location.replace(this.getAttribute("redirectUrl"));}}return false;}};org.openx.SWFObjectUtil.getPlayerVersion=function(){var _23=new org.openx.PlayerVersion([0,0,0]);if(navigator.plugins&&navigator.mimeTypes.length){var x=navigator.plugins["Shockwave Flash"];if(x&&x.description){_23=new org.openx.PlayerVersion(x.description.replace(/([a-zA-Z]|\s)+/,"").replace(/(\s+r|\s+b[0-9]+)/,".").split("."));}}else{if(navigator.userAgent&&navigator.userAgent.indexOf("Windows CE")>=0){var axo=1;var _26=3;while(axo){try{_26++;axo=new ActiveXObject("ShockwaveFlash.ShockwaveFlash."+_26);_23=new org.openx.PlayerVersion([_26,0,0]);}catch(e){axo=null;}}}else{try{var axo=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.7");}catch(e){try{var axo=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.6");_23=new org.openx.PlayerVersion([6,0,21]);axo.AllowScriptAccess="always";}catch(e){if(_23.major==6){return _23;}}try{axo=new ActiveXObject("ShockwaveFlash.ShockwaveFlash");}catch(e){}}if(axo!=null){_23=new org.openx.PlayerVersion(axo.GetVariable("$version").split(" ")[1].split(","));}}}return _23;};org.openx.PlayerVersion=function(_29){this.major=_29[0]!=null?parseInt(_29[0]):0;this.minor=_29[1]!=null?parseInt(_29[1]):0;this.rev=_29[2]!=null?parseInt(_29[2]):0;};org.openx.PlayerVersion.prototype.versionIsValid=function(fv){if(this.major<fv.major){return false;}if(this.major>fv.major){return true;}if(this.minor<fv.minor){return false;}if(this.minor>fv.minor){return true;}if(this.rev<fv.rev){return false;}return true;};org.openx.util={getRequestParameter:function(_2b){var q=document.location.search||document.location.hash;if(_2b==null){return q;}if(q){var _2d=q.substring(1).split("&");for(var i=0;i<_2d.length;i++){if(_2d[i].substring(0,_2d[i].indexOf("="))==_2b){return _2d[i].substring((_2d[i].indexOf("=")+1));}}}return "";}};org.openx.SWFObjectUtil.cleanupSWFs=function(){var _2f=document.getElementsByTagName("OBJECT");for(var i=_2f.length-1;i>=0;i--){_2f[i].style.display="none";for(var x in _2f[i]){if(typeof _2f[i][x]=="function"){_2f[i][x]=function(){};}}}};if(org.openx.SWFObject.doPrepUnload){if(!org.openx.unloadSet){org.openx.SWFObjectUtil.prepUnload=function(){__flash_unloadHandler=function(){};__flash_savedUnloadHandler=function(){};window.attachEvent("onunload",org.openx.SWFObjectUtil.cleanupSWFs);};window.attachEvent("onbeforeunload",org.openx.SWFObjectUtil.prepUnload);org.openx.unloadSet=true;}}if(!document.getElementById&&document.all){document.getElementById=function(id){return document.all[id];};}var getQueryParamValue=org.openx.util.getRequestParameter;var FlashObject=org.openx.SWFObject;var SWFObject=org.openx.SWFObject;document.mmm_fo=1;var OX_66ed2315 = '';
OX_66ed2315 += "<"+"div id=\'ox_b388b2032662e5e7b279b8ffac7aa5c7\' style=\'display: inline;\'><"+"img src=\'http://adserver.dialhost.com.br/www/images/1x1.gif\' alt=\'Planos DialHost\' title=\'Planos DialHost\' border=\'0\' /><"+"/div>\n";
OX_66ed2315 += "<"+"script type=\'text/javascript\'><"+"!--// <"+"![CDATA[\n";
OX_66ed2315 += "var ox_swf = new FlashObject(\'http://adserver.dialhost.com.br/www/images/2f1ae431b47f02f704fd6e827fb20781.swf\', \'Planos DialHost\', \'728\', \'90\', \'8\');\n";
OX_66ed2315 += "ox_swf.addVariable(\'clickTARGET\', \'_blank\');\n";
OX_66ed2315 += "ox_swf.addVariable(\'clickTAG\', \'http%3A%2F%2Fadserver.dialhost.com.br%2Fwww%2Fdelivery%2Fck.php%3Foaparams%3D2__bannerid%3D5__zoneid%3D15__cb%3D97ca9f6d8c__oadest%3Dhttp%253A%252F%252Fwww.dialhost.com.br\');\n";
OX_66ed2315 += "ox_swf.addParam(\'allowScriptAccess\',\'always\');\n";
OX_66ed2315 += "ox_swf.write(\'ox_b388b2032662e5e7b279b8ffac7aa5c7\');\n";
OX_66ed2315 += "if (ox_swf.installedVer.versionIsValid(ox_swf.getAttribute(\'version\'))) { document.write(\"<"+"div id=\'beacon_97ca9f6d8c\' style=\'position: absolute; left: 0px; top: 0px; visibility: hidden;\'><"+"img src=\'http://adserver.dialhost.com.br/www/delivery/lg.php?bannerid=5&amp;campaignid=2&amp;zoneid=15&amp;loc=http%3A%2F%2Fimasters.uol.com.br%2Fartigo%2F2103%2Fjava%2Fexemplo_facil_de_jtable%2F&amp;referer=http%3A%2F%2Fwww.google.com.br%2Fsearch%3Faq%3D0%26oq%3Djtable%26sourceid%3Dchrome%26ie%3DUTF-8%26q%3Djtable+java&amp;cb=97ca9f6d8c\' width=\'0\' height=\'0\' alt=\'\' style=\'width: 0px; height: 0px;\' /><"+"/div>\"); }\n";
OX_66ed2315 += "// ]]> --><"+"/script>\n";
document.write(OX_66ed2315);
