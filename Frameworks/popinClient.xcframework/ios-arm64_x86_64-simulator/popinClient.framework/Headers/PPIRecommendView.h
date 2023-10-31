//
//  PPIRecommendView.h
//
//  v_2.1.0

@import UIKit;
@import WebKit;

#pragma mark - PPIRecommendViewDelegate

@class PPIRecommendView;

// ============
// PPIStatusType
// ============

typedef enum : NSInteger {
    NetworkNotAvailable = 0,
    WebViewLoadingError = 1,
    LayoutErrorWidthExceed = 2,
    LayoutErrorWidthNotEnough = 3,
    Unknown = 4
} PPIStatusType;

// ============
// PPIStatus
// ============

@interface PPIStatus : NSObject

@property (nonatomic, assign) PPIStatusType type;

@end

// ============
// PPIRecommendViewDelegate
// ============

@protocol PPIRecommendViewDelegate <NSObject>

/**
 Callback when WKWebView(or UIViewWeb if OS is lower than 8.0) has finished loading & rendering its contents.
 @param ppiRecommendView PPIRecommendView, itself
 @param size CGSize, size of PPIRecommendView
 @param status PPIStatus, status(network error, page error, etc)
 @returns void
 @exception none
 */
@required
-(void) ppiRecommendView:(PPIRecommendView *)ppiRecommendView didFinishLoadingRequest:(NSURLRequest *)request withSize:(CGSize)size withStatus:(PPIStatus *)status;

/**
 Callback after tap on contents of PPIRecommendView.
 @param ppiRecommendView PPIRecommendView, itself
 @param request NSURLRequest, request of navigation which will occur
 @returns void
 @exception none
 */
@required
-(void) ppiRecommendView:(PPIRecommendView *)ppiRecommendView didTapContentWithRequest:(NSURLRequest*) request;

/**
 Callback when WKWebView(or UIViewWeb if OS is lower than 8.0) changes its contentSize. This may be called several times during web page rendering.
 @param ppiRecommendView PPIRecommendView, itself
 @param size CGSize, size of PPIRecommendView
 @returns void
 @exception none
 */
@required
-(void) ppiRecommendView:(PPIRecommendView *)ppiRecommendView contentSizeChanged:(CGSize) size;
@end

#pragma mark - PPIRecommendView

// ============
// PPIRecommendView
// ============

@interface PPIRecommendView : UIView <WKNavigationDelegate, UIScrollViewDelegate, WKUIDelegate>

@property (nonatomic, weak) id<PPIRecommendViewDelegate> delegate;
@property (nonatomic, retain) NSString* finalUrlString;
@property (nonatomic, retain) NSString* urlString;
@property (nonatomic, retain) NSString* mediaID;

@property (nonatomic, assign) float clickDelay; // default value, 1.0
@property (nonatomic, assign) BOOL isActivityIndicatorVisible;

@property (nonatomic, assign) BOOL isPopinTest;

/**
 Let PPIRecommendView load a specific url.
 This should be called after setting delegate, otherwise callback in delegate may not be recieved.
 @param NSString* web page's url
 @returns void
 @exception none
 */
-(void) loadPopinContentsWithUrlString:(NSString*)urlString
                           withMediaID:(NSString*)mediaID;

- (void)scrollToPositionY:(CGFloat)offsetY;

@end
