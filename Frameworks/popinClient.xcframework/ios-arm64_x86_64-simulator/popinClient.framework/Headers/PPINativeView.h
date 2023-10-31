//
//  PPINativeView.h
//  popinsdk
//
//  Created by Wang Zhenghong on 2016/09/30.
//  Copyright © 2016年 Wang Zhenghong. All rights reserved.
//

// v_1.1.1

@import UIKit;

@class PPIContents;
@class PPINativeView;

/* ============== */
#pragma mark - Delegate

@protocol PPINativeViewDelegate <NSObject>

-(void) ppiNativeView:(PPINativeView *)ppiNativeView contentSizeChanged:(CGSize) size;
-(void) ppiNativeView:(PPINativeView *)ppiNativeView didTapContentWithRequest:(NSURLRequest*) request;

@end

/* ============== */
#pragma mark - PPINativeView

@interface PPINativeView : UIView

@property (nonatomic, weak) id<PPINativeViewDelegate> delegate;
@property (nonatomic, retain) PPIContents* contents;
@property (nonatomic, retain) NSMutableArray* actionUrls;
@property (nonatomic, retain) NSString* urlString;
@property (nonatomic, retain) NSString* mediaID;

-(void)inflateWithLoadedContents;

/**
 Let PPINativeView load contents related to a url. Mostly, the url points a web page of news or report,
 which located in media's web site.
 * This should be called after setting delegate. Otherwise callback in delegate may not be recieved.
 
 @param NSString* A url. Contents(recommendations or ads) related to this webpage will be loaded.
 @returns void
 @exception none
 */
-(void) loadPopinContentsWithUrlString:(NSString*)urlString
                           withMediaID:(NSString*)mediaID;

@end
