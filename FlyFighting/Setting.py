class Settings:
    def __init__(self):
        """设置飞船属性"""
        self.screen_width = 1360
        self.screen_height = 720
        self.bg_color = (230,230,230)
        self.ship_speed_factor = 3
        self.ship_limit = 3

        """设置子弹属性"""
        self.bullet_speed_factor = 1
        self.bullet_width = 3
        self.bullet_height = 10
        self.bullet_color = 60,60,60
        self.bullet_allowed = 40

        """外星人设置"""
        self.alien_speed_factor = 1
        self.fleet_drop_speed =10
        #fleet_direction为1表示向右移，为-1表示向左移
        self.fleet_direction = 1