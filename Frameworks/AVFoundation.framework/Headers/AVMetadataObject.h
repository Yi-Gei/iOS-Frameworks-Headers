/*
	File:  AVMetadataObject.h
 
	Framework:  AVFoundation
 
	Copyright 2012-2013 Apple Inc. All rights reserved.
*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <CoreGraphics/CGGeometry.h>

@class AVMetadataObjectInternal;

/*!
 @class AVMetadataObject
 @abstract
    AVMetadataObject is an abstract class that defines an interface for a metadata object used by AVFoundation.
 
 @discussion
    AVMetadataObject provides an abstract interface for metadata associated with a piece of media.  One example 
    is face metadata that might be detected in a picture. All metadata objects have a time, duration, bounds, and type.
 
    The concrete AVMetadataFaceObject is used by AVCaptureMetadataOutput for face detection.
*/
NS_CLASS_AVAILABLE(NA, 6_0)
@interface AVMetadataObject : NSObject
{
	AVMetadataObjectInternal *_objectInternal;
}

/*!
 @property time
 @abstract
    The media time associated with this metadata object.
 
 @discussion
    The value of this property is a CMTime associated with the metadata object. For capture, it is the time at 
	which this object was captured. If this metadata object originates from a CMSampleBuffer, its time matches
    the sample buffer's presentation time. This property may return kCMTimeInvalid.
*/
@property(readonly) CMTime time;

/*!
 @property duration
 @abstract
    The media duration associated with this metadata object.
 
 @discussion
    The value of this property is a CMTime representing the duration of the metadata object. If this metadata 
    object originates from a CMSampleBuffer, its duration matches the sample buffer's duration. This property 
    may return kCMTimeInvalid.
*/
@property(readonly) CMTime duration;

/*!
 @property bounds
 @abstract
    The bounding rectangle of the receiver.
 
 @discussion
    The value of this property is a CGRect representing the bounding rectangle of the object with respect to the 
    picture in which it resides.  The rectangle's origin is top left.  If the metadata originates from video, bounds 
    may be expressed as scalar values from 0. - 1.  If the original video has been scaled down, the bounds of the 
    metadata object still are meaningful.  This property may return CGRectZero if the metadata has no bounds.
*/
@property(readonly) CGRect bounds;

/*!
 @property type
 @abstract
    An identifier for the metadata object.
 
 @discussion
    The value of this property is an NSString representing the type of the metadata object.  Clients inspecting
    a collection of metadata objects can use this property to filter objects with a matching type.
*/
@property(readonly) NSString *type;

@end

/*!
 @constant AVMetadataObjectTypeFace
 @abstract An identifier for an instance of AVMetadataFaceObject.
 @discussion
    AVMetadataFaceObject objects return this constant as their type.
*/
AVF_EXPORT NSString *const AVMetadataObjectTypeFace;

@class AVMetadataFaceObjectInternal;

/*!
 @class AVMetadataFaceObject
 @abstract
    AVMetadataFaceObject is a concrete subclass of AVMetadataObject defining the features of a detected face.
 
 @discussion
    AVMetadataFaceObject represents a single detected face in a picture.  It is an immutable object
    describing the various features found in the face.

    On supported platforms, AVCaptureMetadataOutput outputs arrays of detected face objects.  See AVCaptureOutput.h.
*/
NS_CLASS_AVAILABLE(NA, 6_0)
@interface AVMetadataFaceObject : AVMetadataObject
{
	AVMetadataFaceObjectInternal *_internal;
}

/*!
 @property faceID
 @abstract
    A unique number associated with the receiver.
 
 @discussion
    The value of this property is an NSInteger indicating the unique identifier of this face in the picture.
    When a new face enters the picture, it is assigned a new unique identifier.  faceIDs are not re-used as
    faces leave the picture and new ones enter.  Faces that leave the picture then re-enter are assigned
    a new faceID.
*/
@property(readonly) NSInteger faceID;

/*!
 @property hasRollAngle
 @abstract
    A BOOL indicating whether the rollAngle property is valid for this receiver.
 
 @discussion
*/
@property(readonly) BOOL hasRollAngle;

/*!
 @property rollAngle
 @abstract
    The roll angle of the face in degrees.
 
 @discussion
    The value of this property is a CGFloat indicating the face's angle of roll (or tilt) in degrees.
    A value of 0.0 indicates that the face is level in the picture.  If -hasRollAngle returns NO,
    then reading this property throws an NSGenericException.
*/
@property(readonly) CGFloat rollAngle;

/*!
 @property hasYawAngle
 @abstract
    A BOOL indicating whether the yawAngle property is valid for this receiver.
 
 @discussion
*/
@property(readonly) BOOL hasYawAngle;

/*!
 @property yawAngle
 @abstract
    The yaw angle of the face in degrees.
 
 @discussion
    The value of this property is a CGFloat indicating the face's angle of yaw (or turn) in degrees.
    A value of 0.0 indicates that the face is straight on in the picture.  If -hasYawAngle returns NO,
    then reading this property throws an NSGenericException.
*/
@property(readonly) CGFloat yawAngle;

@end

/*!
 @constant AVMetadataObjectTypeUPCECode
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeUPCECode.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from UPC-E codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeUPCECode NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypeCode39Code
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeCode39Code.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from Code 39 codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeCode39Code NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypeCode39Mod43Code
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeCode39Mod43Code.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from Code 39 mod 43 codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeCode39Mod43Code NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypeEAN13Code
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeEAN13Code.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from EAN-13 (including UPC-A) codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeEAN13Code NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypeEAN8Code
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeEAN8Code.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from EAN-8 codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeEAN8Code NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypeCode93Code
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeCode93Code.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from Code 93 codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeCode93Code NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypeCode128Code
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeCode128Code.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from Code 128 codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeCode128Code NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypePDF417Code
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypePDF417Code.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from PDF417 codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypePDF417Code NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypeQRCode
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeQRCode.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from QR codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeQRCode NS_AVAILABLE(NA, 7_0);

/*!
 @constant AVMetadataObjectTypeAztecCode
 @abstract An identifier for an instance of AVMetadataMachineReadableCodeObject having a type AVMetadataObjectTypeAztecCode.
 @discussion
    AVMetadataMachineReadableCodeObject objects generated from Aztec codes return this constant as their type.
 */
AVF_EXPORT NSString *const AVMetadataObjectTypeAztecCode NS_AVAILABLE(NA, 7_0);

@class AVMetadataMachineReadableCodeObjectInternal;

NS_CLASS_AVAILABLE(NA, 7_0)
@interface AVMetadataMachineReadableCodeObject : AVMetadataObject
{
	AVMetadataMachineReadableCodeObjectInternal *_internal;
}

/*!
 @property corners
 @abstract
    The points defining the (X,Y) locations of the corners of the machine-readable code.
 
 @discussion
    The value of this property is an NSArray of CFDictionaries, each of which has been created from a CGPoint using 
    CGPointCreateDictionaryRepresentation(), representing the coordinates of the corners of the object with respect to the image 
    in which it resides.  If the metadata originates from video, the points may be expressed as scalar values from 0. - 1. The 
    points in the corners differ from the bounds rectangle in that bounds is axis-aligned to orientation of the captured image, 
    and the values of the corners reside within the bounds rectangle. The points are arranged in counter-clockwise order 
    (clockwise if the code or image is mirrored), starting with the top-left of the code in its canonical orientation.
 */
@property(readonly) NSArray *corners;

/*!
 @property stringValue
 @abstract Returns the receiver’s errorCorrectedData decoded into a human-readable string.
 @discussion
    The value of this property is an NSString created by decoding the binary payload according to the format of the machine
    readable code.  Returns nil if a string representation cannot be created from the payload.
 */
@property(readonly) NSString *stringValue;

@end
