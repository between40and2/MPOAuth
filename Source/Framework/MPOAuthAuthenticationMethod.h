//
//  MPOAuthAuthenticationMethod.h
//  MPOAuthConnection
//
//  Created by Karl Adam on 09.12.19.
//  Copyright 2009 matrixPointer. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const MPOAuthAccessTokenURLKey;

@class MPOAuthAPI;

@interface MPOAuthAuthenticationMethod : NSObject {
	MPOAuthAPI								*__weak oauthAPI_;
	NSURL									*oauthGetAccessTokenURL_;
	NSTimer									*refreshTimer_;
}

@property (nonatomic, readwrite, weak) MPOAuthAPI *oauthAPI;
@property (nonatomic, readwrite, strong) NSURL *oauthGetAccessTokenURL;

- (id)initWithAPI:(MPOAuthAPI *)inAPI forURL:(NSURL *)inURL;
- (id)initWithAPI:(MPOAuthAPI *)inAPI forURL:(NSURL *)inURL withConfiguration:(NSDictionary *)inConfig;

// Juguang
// This init does not need the config to tell what the 3 urls are. instead, they will be set later *manually*
- (id) initWithAPI:(MPOAuthAPI *)inAPI ;



- (void)authenticate;

- (void)setTokenRefreshInterval:(NSTimeInterval)inTimeInterval;
- (void)refreshAccessToken;
@end
