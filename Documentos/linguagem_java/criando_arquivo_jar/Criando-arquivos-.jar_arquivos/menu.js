yp.Registry = []
yp.aniLen = 800
yp.hideDelay = 325
yp.minCPUResolution = 5
function yp(id, dir, left, top, width, height)
{
        this.ie  = document.all ? 1 : 0
        this.ns4 = document.layers ? 1 : 0
        this.dom = document.getElementById ? 1 : 0
        if (this.ie || this.ns4 || this.dom) {
                this.id        = id
                this.dir = dir
                this.orientation = dir == "left" || dir == "right" ? "h" : "v"
                this.dirType = dir == "right" || dir == "down" ? "-" : "+"
                this.dim = this.orientation == "h" ? width : height
                this.hideTimer = false
                this.aniTimer = false
                this.open = false
                this.over = false
                this.startTime         = 20000
                this.gRef = "yp_"+id
                eval(this.gRef+"=this")
                yp.Registry[id] = this
                var d = document
                d.write('<style type="text/css">'+
                '#' + this.id + 'Ct { visibility:hidden; '+
                'left:' + left + 'px; '+
                'top:' + top + 'px; '+
                'overflow:hidden; }'+
                '#' + this.id + 'Ct, #' + this.id + 'Ctt { position:absolute; '+
                'width:' + width + 'px; '+
                'height:' + height + 'px; '+
                'clip:rect(0 ' + width + ' ' + height + ' 0); '+
                '}'+
                '</style>')
                this.load()
        }
}
yp.prototype.load = function() {
        var d = document
        var lyrId1 = this.id + "Ct"
        var lyrId2 = this.id + "Ctt"
        var obj1 = this.dom ? d.getElementById(lyrId1) : this.ie ? d.all[lyrId1] : d.layers[lyrId1]
        if (obj1) var obj2 = this.ns4 ? obj1.layers[lyrId2] : this.ie ? d.all[lyrId2] : d.getElementById(lyrId2)
        var temp
        if (!obj1 || !obj2) window.setTimeout(this.gRef + ".load()", 200)
        else {
                this.container        = obj1
                this.menu = obj2
                this.style        = this.ns4 ? this.menu : this.menu.style
                this.homePos = eval("0" + this.dirType + this.dim)
                this.outPos        = 0
                this.accelConst        = (this.outPos - this.homePos) / yp.aniLen / yp.aniLen 

                if (this.ns4) this.menu.captureEvents(Event.MOUSEOVER | Event.MOUSEOUT);
                this.endSlide()
        }
}        
yp.showMenu = function(id)
{
        var reg = yp.Registry
        var obj = yp.Registry[id]
        if (obj.container) {
                if (id=='mn5' || id=='mn6') {
					
					// Verifica se existe um elemento com nome "clicaSome" e o esconde.
					if (document.getElementById('clicaSome')){ 
					    document.getElementById('clicaSome').style.visibility = "hidden";
				    }
					
					// Verifica se existe um elemento com nome "colunistas" e o esconde.
					if (document.getElementById('selectArticulista')){ 
					    document.getElementById('selectArticulista').style.visibility = "hidden";
				    }
					
				}
                obj.over = true
                if (obj.hideTimer) { reg[id].hideTimer = window.clearTimeout(reg[id].hideTimer) }
                if (!obj.open && !obj.aniTimer) reg[id].startSlide(true)
        }
}
yp.hideMenu = function(id)
{
        var obj = yp.Registry[id]
           if (obj.container) {
                   if (obj.hideTimer) window.clearTimeout(obj.hideTimer)
                   obj.hideTimer = window.setTimeout("yp.hide('" + id + "')", yp.hideDelay);
           }
}
yp.hide = function(id)
{
        var obj = yp.Registry[id]
        obj.over = false
        if (obj.hideTimer) window.clearTimeout(obj.hideTimer)
        obj.hideTimer = 0
        if (obj.open && !obj.aniTimer) obj.startSlide(false)
		
		if (document.getElementById('selectArticulista')){ 
			setTimeout("document.getElementById('selectArticulista').style.visibility = 'visible'", 200);
			clearTimeout();   
		}
		
		if (document.getElementById('clicaSome')){ 
			setTimeout("document.getElementById('clicaSome').style.visibility = 'visible'", 200);
			clearTimeout();   
		}
		
}
yp.prototype.startSlide = function(open) {
        this[open ? "onactivate" : "ondeactivate"]()
        this.open = open
        if (open) this.setVisibility(true)
        this.startTime = (new Date()).getTime()        
        this.aniTimer = window.setInterval(this.gRef + ".slide()", yp.minCPUResolution)
}
yp.prototype.slide = function() {
        var elapsed = (new Date()).getTime() - this.startTime
        if (elapsed > yp.aniLen) this.endSlide()
        else {
                var d = Math.round(Math.pow(yp.aniLen-elapsed, 2) * this.accelConst)
                if (this.open && this.dirType == "-")                d = -d
                else if (this.open && this.dirType == "+")        d = -d
                else if (!this.open && this.dirType == "-")        d = -this.dim + d
                else d = this.dim + d
                this.moveTo(d)
        }
}
yp.prototype.endSlide = function() {
        this.aniTimer = window.clearTimeout(this.aniTimer)
        this.moveTo(this.open ? this.outPos : this.homePos)
        if (!this.open) this.setVisibility(false)
        if ((this.open && !this.over) || (!this.open && this.over)) {
                this.startSlide(this.over)
        }
}
yp.prototype.setVisibility = function(bShow) { 
        var s = this.ns4 ? this.container : this.container.style
        s.visibility = bShow ? "visible" : "hidden"
}
yp.prototype.moveTo = function(p) { 
        this.style[this.orientation == "h" ? "left" : "top"] = this.ns4 ? p : (p) + "px"
}
yp.prototype.getPos = function(c) {
        return parseInt(this.style[c])
}
yp.prototype.onactivate        = function() { }
yp.prototype.ondeactivate = function() { }

var yPosition = 148;
new yp("mn1", "down", 170, yPosition, 206, 530);
new yp("mn2", "down", 234, yPosition, 206, 530);
new yp("mn3", "down", 354, yPosition, 206, 530);
new yp("mn4", "down", 453, yPosition, 206, 530);
new yp("mn5", "down", 529, yPosition, 206, 530);
new yp("mn6", "down", 630, yPosition, 150, 530);

function popup(dochtml, largura, altura, scroll) {
        if(navigator.appName == "Netscape") {
                sec = window.open(dochtml,'_blank','scrollbars=' + scroll + ',toolbar=no,location=no,directories=no,status=yes,menubar=no,resizable=yes,copyhistory=no,height='+ altura +',width='+ largura +',top=51,left=5');
                window.sec.focus();
        }
        else {
                window.open(dochtml,'_blank','scrollbars=' + scroll + ',toolbar=no,location=no,directories=no,status=yes,menubar=no,resizable=no,copyhistory=no,height=' + altura + ',width=' + largura + ',top=51,left=5');
        }
}

function hideElementsById()
{
    document.getElementById('clicaSome').style.visibility = "hidden";
}

function showElementsById()
{
    setTimeout("document.getElementById('clicaSome').style.visibility = 'visible'", 3000);
}
