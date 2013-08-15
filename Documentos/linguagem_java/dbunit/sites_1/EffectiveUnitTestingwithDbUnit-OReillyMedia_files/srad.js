(function()
{
var undef="undefined";
var _Math=Math;
var _window=window;
var _document=document;

var httpPrefix=(location.protocol.indexOf('https')>-1?"https://":"http://");
var isIE=_document.all ? true : false;

//_document.write(srGetConcordance(0));

if (typeof(sr_adserver)==undef)
	sr_adserver=httpPrefix+"ad.afy11.net/ad?";

if (typeof(sr_page_key_1)==undef)
{
	var d=new Date();
	sr_page_key_1=srGetRand();
	sr_page_key_2=d.valueOf()/1000;
}

srValidate();
srConstructGraphicAd();   

function srGetConcordance(i)
{
	return '';
//	return '<img src="'+httpPrefix+'concordance.afy11.net/scripts/concordance.dll?rand='+srGetRand()+'&key=srad-'+i+'-'+sr_adspace_id+'" height=0 width=0 style="display: none">';
}

function srGetRand()
{
	return _Math.round(_Math.random() * 100000000);
}

function srValidate()
{
	// srad.js
	if (typeof(sr_adspace_id)==undef)
		sr_adspace_id = 0;
	if (typeof(sr_alt_adspace_id)!=undef && sr_alt_adspace_id!=null)
	{
		sr_adspace_id = sr_alt_adspace_id;
		sr_alt_adspace_id = null;
	}
	if (typeof(sr_adspace_width)==undef)
		sr_adspace_width = 120;
	if (typeof(sr_adspace_height)==undef)
		sr_adspace_height = 60;
	if (typeof(sr_adspace_type)==undef)
		sr_adspace_type="";
	if (typeof(sr_color_back)==undef)
		sr_color_back="#FFFFFF";
	if (typeof(sr_color_text)==undef)
		sr_color_text="#000000";
	if (typeof(sr_color_url)==undef)
		sr_color_url="#E15F00";
	if (typeof(sr_color_title)==undef)
		sr_color_title="#3F66B3";
	if (typeof(sr_color_border)==undef)
		sr_color_border="#3366CC";
	//if (typeof(sr_color_your_ad)==undef)
	//	sr_color_your_ad="#2852A3";
	//if (typeof(sr_color_your_adbk)==undef)
	//	sr_color_your_adbk="#FFDD81";
	//if (typeof(sr_text_your_ad)==undef)
	//	sr_text_your_ad = "Your ad here";
	//if (typeof(sr_show_footer)==undef)
	//	sr_show_footer = true;

	// disable footer for all ad tags
	//sr_show_footer=false;

	//if (typeof(sr_show_footer_default)==undef)
	//	sr_show_footer_default = sr_show_footer;
	//if (typeof(sr_yah_new_window)==undef)
	//	sr_yah_new_window = false;
	if (typeof(sr_ad_new_window)==undef)
		sr_ad_new_window = false;
	if (typeof(sr_mode)==undef)
		sr_mode = 1;
	if (typeof(sr_popup_type)==undef)
		sr_popup_type = 0;
	if (typeof(sr_popup_interval)==undef)
		sr_popup_interval=1800;
	if (typeof(sr_disable_ie6_iframe)==undef)
		sr_disable_ie6_iframe = false;

	if (navigator.appVersion.indexOf("MSIE 6")!=-1 && sr_disable_ie6_iframe!=true)
	{
		// if already in an iframe, only use iframes to serve the ad
		try
		{	
			if (window.frameElement!=null)
				sr_mode = 0;
		}
		catch (e)
		{
			// if the frame is cross-domain an access denied error will occur
			sr_mode=0;
		}
	}

	if (sr_color_back==sr_color_text || sr_color_back==sr_color_title)
	{
		sr_color_back="#FFFFFF";
		sr_color_text="#000000";
		sr_color_title="#3F66B3";
	}
}

function srConstructGraphicAd()
{
	var mode=sr_mode;
	if (sr_popup_type!=0)
	{
		sr_ad_new_window=true;
		mode=0;
	}
		
	var randomNumber = srGetRand();
	var trueHeight=sr_adspace_height;
	var _encodeURIComponent = (typeof(encodeURIComponent)==undef ? encodeURIComponent2 : encodeURIComponent);
	var descriptor;

	if (sr_adspace_type=="graphic")
		descriptor="2x";
	else
		descriptor="1x";

	descriptor+=sr_adspace_width+"x"+sr_adspace_height;

	var source = sr_adserver +
		'asId='+sr_adspace_id+
		'&sd='+descriptor+
		'&ct='+srTestCapabilities()+
		'&enc='+mode+
		'&sf=0' +
		'&sfd=0' +
		'&ynw=0' +
		'&anw='+(sr_ad_new_window ? "1" : "0") +
		'&rand='+randomNumber +
		'&rk1='+sr_page_key_1 +
		'&rk2='+sr_page_key_2 +
		'&pt='+sr_popup_type;

		//'&yac='+_encodeURIComponent(sr_color_your_ad)+
		//'&ybc='+_encodeURIComponent(sr_color_your_adbk)+
		//'&yat='+_encodeURIComponent(sr_text_your_ad)+
		//'&sf='+(sr_show_footer ? "1" : "0") +
		
		if (typeof(sr_custom0)!=undef)
			source+='&c0='+_encodeURIComponent(sr_custom0);
		if (typeof(sr_custom1)!=undef)
			source+='&c1='+_encodeURIComponent(sr_custom1);
		if (typeof(sr_custom2)!=undef)
			source+='&c2='+_encodeURIComponent(sr_custom2);
		if (typeof(sr_custom3)!=undef)
			source+='&c3='+_encodeURIComponent(sr_custom3);
		if (typeof(sr_custom4)!=undef)
			source+='&c4='+_encodeURIComponent(sr_custom4);
		if (typeof(sr_keyword)!=undef)
			source+='&kd='+_encodeURIComponent(sr_keyword);
        if (typeof (sr_widgetspace_id) != undef && sr_widgetspace_id!=null)
		{
			source+='&wsId='+sr_widgetspace_id;
			sr_widgetspace_id=null;
		}	

		if (typeof(sr_click_count_url)!=undef)
			source+='&trl='+_encodeURIComponent(sr_click_count_url);
		//if (typeof(sr_yah_url)!=undef)
		//	source+='&yao='+_encodeURIComponent(sr_yah_url);
		//if (typeof(sr_debug_ipaddress)!=undef)
		//	source+='&io=VSocial1&xip='+sr_debug_ipaddress;
			
		if (typeof(sr_second_pass)!=undef && sr_second_pass!=null && sr_mode!=0 && typeof(sr_callback_data)!=undef && sr_callback_data!=null)
		{
			source+='&cd='+_encodeURIComponent(sr_callback_data);
			sr_callback_data=null;
			sr_second_pass=null;
		}

		if (sr_adspace_type=="text")
		{
			source+='&bc='+_encodeURIComponent(sr_color_back)+
			'&tc='+_encodeURIComponent(sr_color_text)+
			'&uc='+_encodeURIComponent(sr_color_url)+
			'&ttc='+_encodeURIComponent(sr_color_title)+
			'&bbc='+_encodeURIComponent(sr_color_border);
			//'&yac='+_encodeURIComponent(sr_color_your_ad)+
			//'&ybc='+_encodeURIComponent(sr_color_your_adbk)+
			//'&yat='+_encodeURIComponent(sr_text_your_ad);
		}


	//      alert(source);
	//	document.write(source+"<BR>");

//	if (sr_show_footer && sr_adspace_type=="graphic")
//	{
//		trueHeight+=13;
//	}

	if (sr_popup_type!=0)
	{
		var _currentDate=new Date();
		var _cookie=_document.cookie;
		_document.cookie='srtc1=1; path=/;';
		if(_cookie.indexOf('srtc2=12345') < 0 && _document.cookie.indexOf('srtc1=1') >= 0)
		{
			_currentDate.setTime(_currentDate.getTime()+sr_popup_interval*1000);
			_cookie='srtc2=12345; path=/; expires='+ _currentDate.toGMTString();	
	
			if (!isIE) 
				_document.captureEvents(Event.CLICK);
	
			addEvent(_document, 'click', popWindowEventHandler, false);	
			sr_popup_window_source=source;
		}
	}
	else if (mode==0)
		_document.write('<iframe height="'+trueHeight+'" width="'+sr_adspace_width+'" border="0"  noresize scrolling="no" src="'+source+'" frameborder="0" marginheight="0" marginwidth="0" ></iframe>'+srGetConcordance(1));
	else 
		_document.write('<scr'+'ipt src="'+source+'"></scr'+'ipt>'+srGetConcordance(1));
}

function srTestCapabilities()
{
	function srControlVersion()
	{
		function newActiveXObject(ver)
		{
			return new ActiveXObject("ShockwaveFlash.ShockwaveFlash"+ver);
		}
		
		var version;
		var axo;
		var e;

		function partialTest(ver)
		{
			if (!version)
			{
				try {
					axo = newActiveXObject(ver);
					version = axo.GetVariable("$version");
				} catch (e) {
				}
			}
		}

		function partialTest2(ver, verLong)
		{
			if (!version)
			{
				try {
					axo = newActiveXObject(ver);
					version = verLong;
				} catch (e) {
				}
			}
		}
		
		// NOTE : new ActiveXObject(strFoo) throws an exception if strFoo isn't in the registry

		partialTest(".7");

		if (!version)
		{
			try {
				axo = newActiveXObject(".6");
				version = "WIN 6,0,21,0";
				axo.AllowScriptAccess = "always";
				version = axo.GetVariable("$version");

			} catch (e) {
			}
		}

		partialTest(".3");
		partialTest2(".3", "WIN 3,0,18,0");
		partialTest2("", "WIN 2,0,0,11");

		if (!version)
			version = -1;
		
		return version;
	}

	// JavaScript helper required to detect Flash Player PlugIn version information
	function srGetSwfVer()
	{
		var _navigator=navigator;
		var navigatorAppVersion=_navigator.appVersion;
		var navigatorPlugins=_navigator.plugins;
		var navigatorUserAgent=_navigator.userAgent.toLowerCase();
		// NS/Opera version >= 3 check for Flash plugin in plugin array
		var isIE  = (navigatorAppVersion.indexOf("MSIE") != -1) ? true : false;
		var isWin = (navigatorAppVersion.toLowerCase().indexOf("win") != -1) ? true : false;
		var isOpera = (navigatorUserAgent.indexOf("opera") != -1) ? true : false;
		var flashVer = -1;
		var sf="Shockwave Flash";

		
		if (navigatorPlugins != null && navigatorPlugins.length > 0) 
		{
			if (navigatorPlugins[sf+" 2.0"] || navigatorPlugins[sf]) 
			{
				var swVer2 = navigatorPlugins[sf+" 2.0"] ? " 2.0" : "";
				var flashDescription = navigatorPlugins[sf + swVer2].description;			
				flashVer = flashDescription.split(" ")[2].split(".")[0];
			}
		}
		// MSN/WebTV 2.6 supports Flash 4
		//else if (navigatorUserAgent.indexOf("webtv/2.6") != -1) flashVer = 4;
		// WebTV 2.5 supports Flash 3
		//else if (navigatorUserAgent.indexOf("webtv/2.5") != -1) flashVer = 3;
		// older WebTV supports Flash 2
		//else if (navigatorUserAgent.indexOf("webtv") != -1) flashVer = 2;
		else if ( isIE && isWin && !isOpera ) 
		{
			 flashVer = srControlVersion();
			 if (flashVer!=-1)
				 flashVer=flashVer.split(" ")[1].split(",")[0];
		}	
		return flashVer;
	}
	
	var flashVer=srGetSwfVer();
	if (flashVer>4)
		return 15;
	else
		return 7;
}

function addEvent(elem, eventType, func, uC) 
{
	if (elem.addEventListener) 
	{
		elem.addEventListener(eventType, func, uC);
		return true;
	} 
	else if (elem.attachEvent) 
	{
		return elem.attachEvent('on' + eventType, func);
	} 
	else 
	{
		elem['on' + eventType] = func;
	}
} 

function popWindowEventHandler(evt)
{
	var clkEl= isIE ? event.srcElement : evt.target;
	try
	{
		// only try to pop on hyperlink clicks (most popup blockers allow these kind of popups)
		if( sr_popup_window_source!=null && (isTagParent(clkEl, "A") || isTagParent(clkEl, "INPUT")))
		{
			popWindow(sr_popup_window_source);
			sr_popup_window_source=null;
		}
	 }
	catch(e)
	{
	};  
}	
function isTagParent(tag, type)
{
	if (tag.tagName.toUpperCase()==type)
		return true;

	while (tag.parentNode!=null)
	{
		tag=tag.parentNode;
		if (tag.tagName.toUpperCase()==type)
			return true;
	}

	return false;
}

function popWindow(url)
{
	//t=_Math.round(_Math.random()*250);
	//l=_Math.round(_Math.random()*600);
	if (navigator.appName=="Netscape") 
	{
		oWin=_window.open("","_blank","toolbar=0,location=0,directories=0,status=0,menubar=0,scrollbars=0,resizable=0");
	}
	else
	{
		if (isIE)
		{
			oWin=_window.open("","","toolbar=0,location=0,directories=0,status=0,menubar=0,scrollbars=0,resizable=0,left=-1000,top=-1000,height=200,width=200");
		}
	}

	if (oWin!=null)
	{
		_window.focus();
		oWin.resizeTo(720,300);
		oWin.moveTo(screen.width/2, screen.height/2);
		//		oWin.blur();
		//		oWin.moveTo(l,t);
		oWin.location=url;
	}

	try 
	{
		_window.event.cancelBubble=true;
	}
	catch(e)
	{
	};
}

function encodeURIComponent2(str)
{
	var outStr="";
	for (i=0;i<str.length;i++)
	{
		var code=str.charCodeAt(i);
		if (code==32 || code>33 && code<39 || code>42 && code<48 || code>57 && code<65 || code==91 || code==93 || code==94 || code==96 || code>122 && code<126)
			outStr+=escape(str.charAt(i));
		else if (code>127)
			outStr+="%20";
		else
			outStr+=str.charAt(i);
	}
	return outStr;
}

})()

function srExecute()
{
}

function srDocumentWrite(string)
{
	document.write(string);
}

function srGetAnchor(sourceObj)
{
	var i=0;
	if (sourceObj.childNodes[i].nodeType==3)
		i++;
	
	return sourceObj.childNodes[i].firstChild;
}

function srNavigate(sourceObj, url)
{
	if (srGetAnchor(sourceObj).target=="_new")
	{
		window.open(url);
	}
	else
	{
		window.top.location=url;
	}
}

function srShowStatusI(url) 
{
	window.status = url;
	return true;
}

function srShowStatus(sourceObj) 
{
	window.status = sourceObj.friendlyURL
	return true;
}

function srClearStatus()
{
	window.status='';
}

