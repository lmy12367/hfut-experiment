// miniprogram/page/disable/disableStudyVedio/disableStudyVedio.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    // vedios:[{title:'灯塔公益活动2'},{title:'灯塔公益活动1'},{title:'灯塔公益活动3'},{title:'灯塔公益活动4'},{title:'灯塔公益活动5'}]
    videos:[]
  },
  getViedoInfo:function(){
    var that = this
    wx.request({
      url: 'https://www.bilibili.com/index/ding.json',
      method:'GET',
      success:function(res){
        that.setData({
          videos: res.data.technology
        })
        console.log(res)
        console.log(that.data.videos)
      }
    })
  },
  goHome(){
    wx.redirectTo({
      url: '../disableHome/disableHome',
    })
  },
  goRelease(){
    wx.redirectTo({
      url: '../disableRelease/disableRelease',
    })
  },
  goWork(){
    wx.redirectTo({
      url: '../disableWorks/disableWorks',
    })
  },
  goMyInfo(){
    wx.redirectTo({
      url: '../disableMyInfo/disableMyInfo',
    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.getViedoInfo()
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {
    
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
    
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {
    this.getViedoInfo()
  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {
    //this.getViedoInfo()
  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})