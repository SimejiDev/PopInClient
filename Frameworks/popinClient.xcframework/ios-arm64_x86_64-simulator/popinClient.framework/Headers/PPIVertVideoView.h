@import UIKit;

@class PPIVertVideoView;

/* ============== */
#pragma mark - Delegate

@protocol PPIVertVideoViewDelegate <NSObject>

@optional
-(void) ppiVertVideoView:(nonnull PPIVertVideoView *)ppiVertVideoView didTapJumpBtnWithURL:(nullable NSURL*)url;
-(void) ppiVertVideoView:(nonnull PPIVertVideoView *)ppiVertVideoView startPlayVideoForURL:(nullable NSURL*)videoUrl;
-(void) ppiVertVideoView:(nonnull PPIVertVideoView *)ppiVertVideoView pauseVideoForURL:(nullable NSURL*)videoUrl;

@end

/* ============== */
#pragma mark - PPINativeView

@interface PPIVertVideoView : UIView

@property (nonatomic, weak, nullable) id<PPIVertVideoViewDelegate> delegate;
@property (nonatomic, retain, nullable) NSArray<NSNumber*>* offsetsVideoBegin;
@property (nonatomic, retain, nullable) NSArray<NSNumber*>* offsetsVideoEnd;
@property (nonatomic, retain, nullable) NSArray<NSIndexPath*>* rowIndexesVideoBegin;
@property (nonatomic, retain, nullable) NSArray<NSIndexPath*>* rowIndexesVideoEnd;

@property (nonatomic, retain, nullable) UIScrollView* coverScrollView;
@property (nonatomic, retain, nullable) UITableView* coverTableView;

-(nonnull instancetype)initWithFrame:(CGRect)frame withCoverScrollView:(nonnull UIScrollView*)cover;
-(nonnull instancetype)initWithFrame:(CGRect)frame withCoverTableView:(nonnull UITableView*)cover;

-(void) prepareVideoContents;

@end
