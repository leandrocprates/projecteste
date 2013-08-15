// object to hold custom classes
var OCOM = {};

OCOM.DropDown = Class.create({
 
	initialize: function(options) {
		// pass object that contains
		// element (ul)
		this.options = options;
		this.defaults = $H({
			name: 'DropDown',
		
			vertical_adjustment: 0,
			
			classes: {
				hover: 'hover',
				first: 'first',
				last: 'last',
				top_level: 'top-level',
				sub_level: 'sub-level',
				bottom_level: 'bottom-level'
			},
			
			events: {
				enter: 'dropdown:enter',
				leave: 'dropdown:leave'
			},
			
			debug: true
		
		});	
	
		this.defaults.merge(this.options).each(function(o){
			this[o[0]] = o[1];
		}.bind(this));
				
		this.events = $H(this.defaults.get('events')).merge(this.events).toObject();
		this.classes = $H(this.defaults.get('classes')).merge(this.classes).toObject();
	
		this.setup();
	},

	setup: function(){
		this.setup_elements();
		this.setup_markup();
		this.setup_observers();
	},

	setup_elements: function(){		
		this.kids = this.element.childElements();
		this.kids.each(function(link){
			victim = link.select('span').first();
			this.vertical_center(victim);
		}.bind(this));
	},

	setup_markup: function(){
		this.kids.invoke('addClassName', this.classes.top_level);
		this.element.select('li:first-child').invoke('addClassName', this.classes.first);
		this.element.select('li:last-child').invoke('addClassName', this.classes.last);
		
		if(Prototype.Browser.IE){
			this.element.select('li.top-level>ul').each(function(submenu){
				var w = submenu.getWidth();
				submenu.setStyle({
					whiteSpace: 'nowrap',
					width: submenu.getWidth()+'px'
				});	
			});
		}
		
		this.element.select('li').each(function(item){
			if(item.down('ul')){
				item.addClassName('hasSubmenu');
			}
		});
	},

	setup_observers: function(){
			// allows custom mouse enter/leave events
			// on this.element
			firstCommonAncestor = this.firstCommonAncestor;
			stopEvent = this.stopEvent;
		this.element.observe('mouseout', function(e){
			
			var from = e.element();
			
			var to = e.relatedTarget;
			p = null;
			if ( !to || (from !== to && !to.descendantOf(from))) {
				/* mouseleave should bubble up until the to element because we have left all elements up to that one */
				var stopOn = null;
				if( to ){
					if( from.descendantOf(to) ){
						stopOn = to.childElements();
					}else{
						p = firstCommonAncestor(from, to);
						if( p && to.descendantOf(p) ){
							stopOn = p.childElements();
						}
					}
				}
				if( stopOn ){
					stopOn.invoke('observe', 'custom:mouseleave', stopEvent);
				}
				from.fire('custom:mouseleave');
				if( stopOn ){
					stopOn.invoke('stopObserving', 'custom:mouseleave', stopEvent);
				}
			}
			var p = null;
			if( to && !from.descendantOf(to)){
				/* mouseenter can bubble, no problem! */
				var stopOn = null;
				if( to.descendantOf(from)){
					stopOn = from.childElements();
				}else{
					// do first common ancestor's children, see below.
					p = firstCommonAncestor(to, from);
					stopOn = p.childElements();
				}
				if( stopOn ){
					stopOn.invoke('observe', 'custom:mouseenter', stopEvent);
				}
				to.fire('custom:mouseenter');
				if( stopOn ){
					stopOn.invoke('stopObserving', 'custom:mouseenter', stopEvent);
				}
			}
		});
		
		this.element.select('li').each(function(item){
			item.observe('mouseenter', function(hover){
				if(hover.element().hasClassName('hasSubmenu') ){
					hover.element().addClassName('hasSubmenu-' + this.classes.hover);
				}

				hover.element().addClassName(this.classes.hover);
			}.bindAsEventListener(this));
			
			item.observe('mouseleave', function(hover){
				if(hover.element().hasClassName('hasSubmenu-'+this.classes.hover) ){
					hover.element().removeClassName('hasSubmenu-' + this.classes.hover);
				}
				
				hover.element().removeClassName(this.classes.hover);
			}.bindAsEventListener(this));
		}.bind(this));
		
	},
		
	vertical_center: function(el){
		if(el && el.up()){
			p = el.up();

			el.setStyle({height: 'auto'});
			pHeight = p.offsetHeight;
			eHeight = el.offsetHeight;
			y = 0;
			if(pHeight > eHeight){
				y = (pHeight/2) - (eHeight/2);	
			} else {
				y = 0;
			}
			
			y += this.vertical_adjustment;
			
			el.setStyle({
				marginTop: y+'px'
			});
		}
	},
	
	firstCommonAncestor: function(elm1, elm2){
		var p = elm1.up();
		while( !elm2.descendantOf(p) ){
			p = p.up();
		}
		return p;
	},
	
	stopEvent: function(e){
		try{
			e.stop();
		}catch(ex){}
	}
});el>ul').each(function(submenu){
				var w = submenu.getWidth();
				submenu.setStyle({
					whiteSpace: 'nowrap',
					width: submenu.getWidth()+'px'
				});	
			});
		}
		
		this.element.select('li').each(function(item){
			if(item.down('ul')){
				item.addClassName('hasSubmenu');
			}
		});
	},

	setup_observers: function(){
			// allows custom mouse enter/leave events
			// on this.element
			firstCommonAncestor = this.firstCommonAncestor;
			stopEvent = this.stopEvent;
		this.element.observe('mouseout', function(e){
			
			var from = e.element();
			
			var to = e.relatedTarget;
			p = null;
			if ( !to || (from !== to && !to.descendantOf(from))) {
				/* mouseleave should bubble up until the to element because we have left all elements up to that one */
				var stopOn = null;
				if( to ){
					if( from.descendantOf(to) ){
						stopOn = to.childElements();
					}else{
						p = firstCommonAncestor(from, to);
						if( p && to.descendantOf(p) ){
							stopOn = p.childElements();
						}
					}
				}
				if( stopOn ){
					stopOn.invoke('observe', 'custom:mouseleave', stopEvent);
				}
				from.fire('custom:mouseleave');
				if( stopOn ){
					stopOn.invoke('stopObserving', 'custom:mouseleave', stopEvent);
				}
			}
			var p = null;
			if( to && !from.descendantOf(to)){
				/* mouseenter can bubble, no problem! */
				var stopOn = null;
				if( to.descendantOf(from)){
					stopOn = from.childElements();
				}else{
					// do first common ancestor's children, see below.
					p = firstCommonAncestor(to, from);
					stopOn = p.childElements();
				}
				if( stopOn ){
					stopOn.invoke('observe', 'custom:mouseenter', stopEvent);
				}
				to.fire('custom:mouseenter');
				if( stopOn ){
					stopOn.invoke('stopObserving', 'custom:mouseenter', stopEvent);
				}
			}
		});
		
		this.element.select('li').each(function(item){
			item.observe('mouseenter', function(hover){
				if(hover.element().hasClassName('hasSubmenu') ){
					hover.element().addClassName('hasSubmenu-' + this.classes.hover);
				}

				hover.element().addClassName(this.classes.hover);
			}.bindAsEventListener(this));
			
			item.observe('mouseleave', function(hover){
				if(hover.element().hasClassName('hasSubmenu-'+this.classes.hover) ){
					hover.element().removeClassName('hasSubmenu-' + this.classes.hover);
				}
				
				hover.element().removeClassName(this.classes.hover);
			}.bindAsEventListener(this));
		}.bind(this));
		
	},
		
	vertical_center: function(el){
		if(el && el.up()){
			p = el.up();

			el.setStyle({height: 'auto'});
			pHeight = p.offsetHeight;
			eHeight = el.offsetHeight;
			y = 0;
			if(pHeight > eHeight){
				y = (pHeight/2) - (eHeight/2);	
			} else {
				y = 0;
			}
			
			y += this.vertical_adjustment;
			
			el.setStyle({
				marginTop: y+'px'
			});
		}
	},
	
	firstCommonAncestor: function(elm1, elm2){
		var p = elm1.up();
		while( !elm2.descendantOf(p) ){
			p = p.up();
		}
		return p;
	},
	
	stopEvent: function(e){
		try{
			e.stop();
		}catch(ex){}
	}
});